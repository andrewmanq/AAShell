/*
 * CommandLine.h
 * 
 * This class takes an istream& argument and parses the input of a command line user.
 * Warning: will immediately halt program for user input upon creation
 *
 *  Created on: Mar 26, 2019
 *      Author: anq3
 */


#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
#include <bits/stdc++.h>

class CommandLine {
public:
	
	CommandLine(istream& in);
	char * getCommand() const; //returns a pointer to the command portion of the command line (argv0)
	int getArgCount() const; // returns the number of command-line arguments on the command-line (i.e., argc). 
	char ** getArgVector() const; //returns a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv).
	char * getArgVector(int i) const; //returns a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]). 
	bool noAmpersand() const; //returns true if and only if no ampersand was given on the command-line 
private:
	int argc;
	char ** argv;
	vector<char*> charVec;
	bool ampersand;
};

#endif