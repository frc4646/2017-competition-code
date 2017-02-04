#!/bin/sh

#cd $(dirname $0)
cd $(dirname $(readlink -f $0))
cd mjpg-streamer-experimental
LD_LIBRARY_PATH=$(pwd)/_build/plugins/output_http/:$(pwd)/_build/plugins/input_uvc/ exec ./mjpg_streamer -i "./input_uvc.so -d /dev/video0 -f 30 -r 320x240 -y -n -br 30 -ex 5" -o "./output_http.so -w ./www -p 1180" &
