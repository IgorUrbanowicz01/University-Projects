#/bin/bash
declare -A words_files

dir="$1"
for file in $(./Zadanie1.sh $dir); do
    declare -A current_file
    for word in $(cat $dir$file); do
        if [ ! ${current_file["$word"]+yup} ]; then
            words_files["$word"]+=" $file"
            current_file["$word"]="a"
        fi
    done
    unset current_file
done

for word in "${!words_files[@]}"; do
    printf -- "word: $word\n"
    for file in ${words_files["$word"]}; do
        printf "file: $file\ncontains: "
        grep -w -- "$word" "$dir$file" | sed 's/^/    /'
    done
    printf "\n"
done
