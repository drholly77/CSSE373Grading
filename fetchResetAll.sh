#!/bin/bash
#
# Fetch most recent commit/pushes from student repos
# Run fetchResetAll:
# 1) after you have used the cloneAll script
# 2) right before grading a student assignment
#
# Double click to run - at least that worked on my Windows machine
#
# To run from a Bash command line type: ./fetchResetAll
# You might need to make this file an executable
#   To do that at a Bash command line type:  chmod u+x fetchResetAll.sh
#
# This will loop through all subdirectories and use git
# to retrieve the latest commit. No merge conflicts, etc.
# It uses git's fetch and reset --hard commands
#
for FILE in csse373devenv202430*; do 
	cd $FILE 
	echo "fetching $FILE"
	git fetch
	git reset --hard origin/main
	cd ..
done
echo "Done fetching"


