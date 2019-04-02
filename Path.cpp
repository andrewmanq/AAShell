/*
 * Path.cpp
 * Written by Alex Vander Tuig and Andrew Quist
 * Written for CS 232A, Prof. Adams at Calvin College
 * 4/2/19
 * Project 3
 * 
 * 
 * Method declarations for Path Class
 */

#include "Path.h"
#include <stdlib.h>
#include <sys/types.h>  //DIR*
#include <dirent.h> //struct dirent

using namespace std;

/*
 * Constructor that fills myDirectories with directories from PATH 
 * Environment variable.
 */
Path::Path () {
	char * ptr;
    ptr= getenv ("PATH"); //get ptr to PATH
    string entry=""; //declare empty string
    //go through each character in C-String pointed to by path
    // if character is ':"', marks end of one directory, beginning of next
    for (char* charPtr= ptr; *charPtr; charPtr++) {
        if (*charPtr == ':') {
            myDirectories.push_back (entry); //add entry to myDirectories
            entry=""; //clear entry
        } else {
            entry=entry + *charPtr; //concatenate character to entry string
        }
    }
}

//return the directory at index i
string Path::getDirectory (const int i) const {
    return myDirectories [i];
}

// see if a program can be found in any of the directories in myDirectories
// return the index of the directory if found, else return -1
int Path::find(const string& program) const {
    int index=-1; 
    for (unsigned i=0; i<myDirectories.size(); i++) {
        DIR* dirPtr=opendir (myDirectories[i].c_str()); //get ptr to DIR and open it
        if (!dirPtr) { //dirPtr is NULL, myDirectories[i] doesn't exist
            continue;
        }
        struct dirent * entryPtr; //create struct dirent ptr
        //iterate through everything in directory 
        while ((entryPtr=readdir(dirPtr)) != NULL) {
            //if name of element in directory == program, return i
            if (entryPtr->d_name == program) {
                index=i;
                return index;
            }
        }
    }
    return index; //program not found 
}
