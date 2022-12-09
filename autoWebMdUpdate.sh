#!/bin/bash
# Get update folder name
echo Updated folder is $1
echo The script will update these file to GitHub page branch:
out=$( ls $1 | grep ".*.md" )
echo -e "\t$out"
folder=$( echo `echo $1 | sed "s&\.$&&" | sed "s&/$&&"` )
# Change to GitHub branch
git checkout gh-pages
# Update index file
echo ====Update index.md file====
git checkout master index.md
git add index.md
git commit -m "Update question list @ `date +'%Y/%m/%d'`"
# Update new note
echo ====Update note file====
git checkout master `echo $folder/$out`
mv `echo $folder/$out` `echo pages/$out`
git restore --staged `echo $folder/$out`
git add pages/$out
git commit -m "Update note of $out @ `date +'%Y/%m/%d'`"
echo ====Pull all commits====
git push
git reset
git clean
git checkout master