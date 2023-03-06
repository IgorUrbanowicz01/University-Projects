#!/bin/bash

dir="$1"

find $dir -type f -printf "%f\n" | tr '[:space:]' '[\n*]' | grep -v "^\s*$" | sort | uniq -c | sort -bnr