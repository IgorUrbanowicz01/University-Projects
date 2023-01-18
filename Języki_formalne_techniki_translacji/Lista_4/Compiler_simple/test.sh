#!/bin/bash


for FILE in $(find tests/ | grep ".in")
do
	FILE_NAME="$( echo "$FILE" | cut -d'.' -f1 )"
	echo TEST FOR $FILE_NAME
	OUTPUT_FILE="$( echo $FILE_NAME ).out"
	CORRECT_FILE="$( echo $FILE_NAME ).correct"
	
	./kompilator $FILE $OUTPUT_FILE > $OUTPUT_FILE
	sudo ./virtual-machine/maszyna-wirtualna $OUTPUT_FILE
done