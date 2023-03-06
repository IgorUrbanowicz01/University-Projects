#!/bin/bash

dir="$1"
dir=${dir%/}

find $dir -type f -printf "%f\n"