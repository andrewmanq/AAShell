/*
 * Prompt.cpp
 * Written by Alex Vander Tuig and Andrew Quist
 * Written for CS 232A, Prof. Adams at Calvin College
 * 4/2/19
 * Project 3
 * 
 * 
 * Members for Prompt class.
 */

#include "Prompt.h"
#include <unistd.h>

//get the Current working directory and store it
Prompt::Prompt () {
	char array[1000];
	getcwd(array, 1000);
	myCWD=string (array);
}

//return myCWD
string Prompt::get() const {
	return myCWD;
}
