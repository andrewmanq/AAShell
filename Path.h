/*
 * Path.h
 * Written by Alex Vander Tuig and Andrew Quist
 * Written for CS 232A, Prof. Adams at Calvin College
 * 4/2/19
 * Project 3
 * 
 * 
 * Declares Path Class that gets the directories in the PATH environment variable
 * and provides methods to search the directories for programs.
 */

#ifndef PATH_H_
#define PATH_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Path {
public:
	Path();
    string getDirectory (const int i) const;
    int find(const string& program) const;
private:
    vector<string> myDirectories;
};

#endif /* PATH_H_ */