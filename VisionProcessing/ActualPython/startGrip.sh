#!/bin/bash --login

cd $(dirname $(readlink -f $0))

workon cv
python asap_find_lines.py &
python asap_find_lines_2.py &

