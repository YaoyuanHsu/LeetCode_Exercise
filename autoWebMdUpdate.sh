#!/bin/bash
# Get update folder name
echo Updated folder is $1
echo The script will update these file to GitHub page branch:
out=$( ls $1 | grep ".*.md" )
echo $out
folder=$( echo `echo $1 | sed "s&\.$&&"` )
# Change to GitHub branch
git checkout gh-pages
# Update index file
git checkout index.md
git add index.md
git commit -m "Update question list @ `date +'%Y/%m/%d'`"
# Update new note
git chekout master `echo $folder$out`
mv `echo $folder$out` `echo ./pages/$out`
git restore --staged `echo $folder$out`
git add pages/$out
git commit -m "Update note of $out @ `date +'%Y/%m/%d'`"
git pull