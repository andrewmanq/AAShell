
#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
#include <bits/stdc++.h>

class CommandLine {
public:
	
	CommandLine(istream& in);
	string getCommand() const; //returns a pointer to the command portion of the command line (argv0)
	int getArgCount() const; // returns the number of command-line arguments on the command-line (i.e., argc). 
	vector<string> getArgVector() const; //returns a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv).
	string getArgVector(int i) const; //returns a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]). 
	bool noAmpersand() const; //returns true if and only if no ampersand was given on the command-line 
private:
	int argc;
	std::vector<string> argv;

};

#endif