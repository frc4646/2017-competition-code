#!/bin/sh

camera1=/dev/v4l/by-path/platform-3f980000.usb-usb-0:1.2:1.0-video-index0
camera2=/dev/v4l/by-path/platform-3f980000.usb-usb-0:1.4:1.0-video-index0

#cd $(dirname $0)
cd $(dirname $(readlink -f $0))
cd mjpg-streamer-experimental
LD_LIBRARY_PATH=$(pwd)/_build/plugins/output_http/:$(pwd)/_build/plugins/input_uvc/ exec ./mjpg_streamer -i "./input_uvc.so -d $camera1 -f 30 -r 320x240 -y -n -br 30 -ex 5" -o "./output_http.so -w ./www -p 1180" &
LD_LIBRARY_PATH=$(pwd)/_build/plugins/output_http/:$(pwd)/_build/plugins/input_uvc/ exec ./mjpg_streamer -i "./input_uvc.so -d $camera2 -f 30 -r 320x240 -y -n -br 30 -ex 5" -o "./output_http.so -w ./www -p 1181" &
