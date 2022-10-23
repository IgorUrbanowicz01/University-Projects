#!/bin/bash


read -p 'Path: ' path
ls $path
read -p 'Word: ' word
grep -irm 1 $word $path | wc -l