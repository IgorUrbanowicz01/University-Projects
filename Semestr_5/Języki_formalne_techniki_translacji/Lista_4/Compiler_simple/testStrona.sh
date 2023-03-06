#!/bin/bash


for FILE in $(find test_strona/ | grep ".imp")
do
	FILE_NAME="$( echo "$FILE" | cut -d'.' -f1 )"
	echo TEST FOR $FILE_NAME:
	OUTPUT_FILE="$( echo $FILE_NAME ).out"

	./kompilator $FILE $OUTPUT_FILE
	./virtual-machine/maszyna-wirtualna $OUTPUT_FILE
done