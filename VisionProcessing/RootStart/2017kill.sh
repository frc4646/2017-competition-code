#!/bin/bash

kill $(pgrep mjpg_streamer)

#warning this may kill too much stuff
kill $(pgrep python)
