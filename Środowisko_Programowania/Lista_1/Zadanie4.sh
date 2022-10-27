#/bin/bash
declare -A words_files

dir="$1"
for file in $(./Zadanie1.sh $dir); do
    declare -A current_file
    for word in $(cat $file); do
        if [ ! ${current_file["$word"]+yup} ]; then
            words_files["$word"]+=" $file"
            current_file["$word"]="a"
        fi
    done
    unset current_file
done

for word in "${!words_files[@]}"; do
    printf -- "\033[38;5;45mthe word ‘\033[0m$word\033[38;5;45m’ \033[38;5;45mappeared in:\033[0m\n"
    for file in ${words_files["$word"]}; do
        printf "    \033[38;5;81ma file named ‘\033[0m$file\033[38;5;81m’:\033[0m\n"
        grep -w -- "$word" "$file" | sed 's/^/    /'
    done
    printf "\n"
done
