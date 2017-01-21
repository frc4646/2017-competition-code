#!/bin/bash --login

cd $(dirname $(readlink -f $0))
whoami

workon cv
python asap_find_lines.py

