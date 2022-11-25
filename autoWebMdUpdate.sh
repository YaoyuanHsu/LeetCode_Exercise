#!/bin/bash
# Get update folder name
echo Updated folder is $1
echo The script will update these file to GitHub page branch:
out=$( ls $1 | grep ".*.md" )
echo $out
folder=$( echo `echo $1 | sed "s&.$&&"` )
echo $folder$out
#git checkout gh-pages