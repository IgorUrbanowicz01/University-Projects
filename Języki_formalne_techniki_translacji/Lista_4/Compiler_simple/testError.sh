#!/bin/bash


for FILE in $(find errorTests/ | grep ".imp")
do
	FILE_NAME="$( echo "$FILE" | cut -d'.' -f1 )"
	echo TEST FOR $FILE_NAME:

	./kompilator $FILE
done