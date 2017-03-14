#!/usr/bin/python3

"""
"""

import cv2
from networktables import NetworkTables
from grip import GripPipeline
import time
import socket

networktableHostname = '10.46.46.2'
networktablePort = 1735
cameraHostname = 'localhost'

myCameraPort = 1180

myCameraInstance = "Front"

def wait_for_port_open(hostname, portNumber):
    s = socket.socket()
    while True:
        try:
            s.connect((hostname, portNumber))
        except socket.timeout as err:
            pass
        except socket.error as err:
            pass
        else:
            s.close()
            return

def extra_processing(pipeline, CAMERA_INSTANCE):
    """
    Performs extra processing on the pipeline's outputs and publishes data to NetworkTables.
    :param pipeline: the pipeline that just processed an image
    :return: None
    """
    center_x_positions = []
    center_y_positions = []
    widths = []
    heights = []

    # Find the bounding boxes of the contours to get x, y, width, and height
    for contour in pipeline.filter_contours_output:
        x, y, w, h = cv2.boundingRect(contour)
        center_x_positions.append(x + w / 2)  # X and Y are coordinates of the top-left corner of the bounding box
        center_y_positions.append(y + h / 2)
        widths.append(w)
        heights.append(h)

    # Publish to the '/vision/red_areas' network table
    table = NetworkTables.getTable('/vision/targets_%s' % CAMERA_INSTANCE)
    table.putNumberArray('centerX', center_x_positions)
    table.putNumberArray('centerY', center_y_positions)
    table.putNumberArray('width', widths)
    table.putNumberArray('height', heights)


def main(cameraPort, CAMERA_INSTANCE):
    print('Waiting on network tables')
    wait_for_port_open(networktableHostname, networktablePort)
    print('Network tables available')
    print('Waiting on camera')
    wait_for_port_open(cameraHostname, cameraPort)
    print('Camera available')

    print('Initializing NetworkTables')
    NetworkTables.setClientMode()
    NetworkTables.setIPAddress(networktableHostname)
    NetworkTables.initialize()
    table = NetworkTables.getTable('/vision/diagnostic_%s' % CAMERA_INSTANCE)


    print('Creating video capture')
#    cap = cv2.VideoCapture(0)
    cap = cv2.VideoCapture('http://%s:%d/?action=stream' % (cameraHostname, cameraPort))

    print('Creating pipeline')
    pipeline = GripPipeline()

    if cap.isOpened():
        print('opened capture')
    print('Running pipeline')

    i = 0
    previous_frame_time = time.time()
    while cap.isOpened():
        have_frame, frame = cap.read()
        if have_frame:
            frame_start = time.time()
            pipeline.process(frame)
            extra_processing(pipeline, CAMERA_INSTANCE)
			frame_end = time.time()
            frame_interval = frame_start - previous_frame_time
            frame_rate = 1 / (frame_interval)
            frame_time = frame_end - frame_start
            previous_frame_time = frame_start
            i += 1
            table.putNumber('count', i)
            table.putNumber('frameRate', frame_rate)
            table.putNumber('frameTime', frame_time)
            table.putNumber('frameInterval', frame_interval)

    print('Capture closed')


if __name__ == '__main__':
    main(myCameraPort, myCameraInstance)
