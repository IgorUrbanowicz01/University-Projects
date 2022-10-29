#!/bin/bash

dir="$1"

for file in $(./Zadanie1.sh "$dir"); do
    cat "$dir$file" | tr a A > /tmp/.temporary-ex-5
    rm "$dir$file"
    mv /tmp/.temporary-ex-5 "$dir$file"
done