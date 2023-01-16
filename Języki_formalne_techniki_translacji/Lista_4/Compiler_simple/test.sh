#!/bin/bash


for FILE in $(find tests/ | grep ".in")
do
	FILE_NAME="$( echo "$FILE" | cut -d'.' -f1 )"
	echo TEST FOR $FILE_NAME
	OUTPUT_FILE="$( echo $FILE_NAME ).out"
	CORRECT_FILE="$( echo $FILE_NAME ).correct"
	
	./kompilator $FILE $OUTPUT_FILE > $OUTPUT_FILE
	OUTPUT_CODE="$(echo "$( sudo virtual-machine/maszyna-wirtualna $OUTPUT_FILE)" | grep ">")"
	DIFF=$( diff $CORRECT_FILE <( echo "$OUTPUT_CODE" ) )
	
	if [ "$DIFF" == "" ]
	then
		echo -e "\n $FILE succeded!\n"
	else
		echo -e "\ $FILE failed!\n"
	fi
done