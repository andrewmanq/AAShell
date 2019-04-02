/*
 * Prompt.h
 * Written by Alex Vander Tuig and Andrew Quist
 * Written for CS 232A, Prof. Adams at Calvin College
 * 4/2/19
 * Project 3
 * 
 * 
 * Declares Prompt Class that gets current working directory, and prints it to console.
 */

#ifndef PROMPT_H_
#define PROMPT_H_

using namespace std;

#include <string>

class Prompt {
public:
	Prompt();
	string get() const;
private:
	string myCWD;
};

#endif /* PROMPT_H_ */
