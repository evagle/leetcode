#!/bin/bash
##
# @file run.sh
# @Brief 
# @author  Brian 
# @version 1.0
# @date 2013-08-26

g++ -g -std=c++0x $1
if [ $? -eq 0 ]; then
    ./a.out
else 
    echo "Compile Error"
fi
