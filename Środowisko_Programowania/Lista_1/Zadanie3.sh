declare -A stats

dir="$1"

for file in $(./Zadanie1.sh $dir); do
    declare -A current_file
    for word in $(cat $file); do
        if [ ! ${current_file["$word"]+yup} ]; then
            if [ ${stats["$word"]+yup} ]; then
                ((stats['$word']++))
            else
                ((stats['$word']=1))
            fi
            current_file["$word"]="a"
        fi
    done
    unset current_file
done

for word in "${!stats[@]}"; do
    printf -- "\033[38;5;45mthe word ‘\033[0m$word\033[38;5;45m’ \033[38;5;45mappeared in ${stats[$word]} file(s)\033[0m\n"
done
