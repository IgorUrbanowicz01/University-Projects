#!/bin/bash

for FILE in $(find tests/ | grep ".imp")
do
	FILE_NAME="$( echo "$FILE" | awk '{ print substr( $0, 1, length($0) - 4 ) }' )"
	OUTPUT_FILE="$( echo $FILE_NAME ).mr"
	CORRECT_FILE="$( echo $FILE_NAME )_correct.out"
	
	./kompilator $FILE $OUTPUT_FILE > $OUTPUT_FILE
	OUTPUT_CODE="$(echo "$( sudo virtual-machine/maszyna-wirtualna $OUTPUT_FILE)" | grep ">")"
	DIFF=$( diff $CORRECT_FILE <( echo "$OUTPUT_CODE" ) )
	
	if [ "$DIFF" == "" ]
	then
		echo -e "\nTest $FILE completed!\n"
	else
		echo -e "\nest $FILE failed!\n"
	fi
done