#!/bin/bash

read -p 'Path: ' path

find $path -type f -printf "%f\n" | tr '[:space:]' '[\n*]' | grep -v "^\s*$" | sort | uniq -c | sort -bnr