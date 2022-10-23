#!/bin/bash


read -p 'Path: ' path

find $path -type f -printf "%f\n"