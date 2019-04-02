/*
 * AAShell.h
 * 
 * The AAShell is the program's manager. It runs programs according to user input and uses multithreading if neccessary.
 * Instructions: constructor needs no input. To execute the manager, use AAShell::run();
 * 
 *  Created on: Mar 26, 2019
 *      Author: ajv98 and anq3
 */

#ifndef AASHELL_H_
#define AASHELL_H_

#include "Path.cpp"
#include "Prompt.cpp"
#include "CommandLine.cpp"

using namespace std;

class AAShell {
public:
	//empty constructor, initializes the system path
	AAShell();
	//Runs the entire shell program using user input
	void run();
private:
	//pwd exposes the working directory, prints it to command line
	void pwd();
	//cd changes the working directory to argv[1] of the predetermined CommandLine class
	void cd(CommandLine cl);
	Path myPath;
};

#endif /* AASHELL_H_ */