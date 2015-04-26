#! /bin/bash

# usage : ./test => run all the tests of the folders
# usage : ./test file.h => run the test for the file
# 			Write the name of the file directly, not
#			the path to the file.

sub_folder=( ./libmath/test );

for i in ${sub_folder}
do
	# run in a subshell (that's what parenthesis mean)
	(
	echo "###In folder $i";
	cd $i
	./test.sh $@ 
	)
done
