#!/bin/bash

rev1="$1"
rev2="$2"

svn_dir="$3"

# extract the directory name
dir=${svn_dir%/}
dir="${dir##*/}"

# initialize an empty git repository
git init "$dir"

cd "$dir"

for r in $(seq $rev1 $rev2); do

    svn log -q -r "$r" "$svn_dir"
    if [ $? == "1" ]; then
        continue
    fi

    rm -rf *
    svn export --force -q "$svn_dir" -r "$r" "./"

    msg="$(svn log -r $r $svn_dir | tail -n +4 | head -n -2)"

    git add "./**/*"
    git commit -m "$msg"

done
