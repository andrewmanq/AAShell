/*
 * AAShell.cpp
 * 
 * The AAShell is the program's manager. It runs programs according to user input and uses multithreading if neccessary.
 * Instructions: constructor needs no input. To execute the manager, use AAShell::run();
 * 
 *  Created on: Mar 26, 2019
 *      Author: ajv98 and anq3
 */

#include "AAShell.h"
#include "sys/wait.h"

AAShell::AAShell () {
	Path myPath;
}

void AAShell::run() {
	while (1) {
		Prompt myPrompt;
		//prints out the working directory
		cout <<  myPrompt.get() << "$ ";
		//myCommandLine takes commands from the user, stores them
		CommandLine myCommandLine (cin);
		char* command = myCommandLine.getCommand();
		string commandStr= string (command);

		int index= myPath.find (commandStr);
		if (commandStr == "cd") {
			cd(myCommandLine); //calls the built-in cd() function
		} else if (commandStr == "pwd") {
			pwd(); //calls the built-in pwd() function
		} else if (commandStr == "q") {
			break;
		} else if ( index >= 0 ) {
			//call system program
			int pid= fork();
			if (pid == -1) {
				cerr << "Failed to create new child process" << endl;
				exit (2);
			} else if (pid == 0) {
				//child
				string program= myPath.getDirectory(index) + "/" + commandStr;
				execve (program.c_str(), myCommandLine.getArgVector(), environ);
				cout << "There was an issue executing this program, is it a binary executable?" << endl;
				exit(3);
			} else {
				//parent
				if(myCommandLine.noAmpersand()){
					waitpid(pid, NULL, 0);
				}
			}
		} else {
			cout << "That is not a recognized command" << endl;
			cout << "If desired, use command \"q\" to quit" << endl;
		}
	}
}

//runs a local implementation of the classic pwd unix command
void AAShell::pwd() {
	char array[1000];
	getcwd(array, 1000);
	cout << array << endl;
}

//runs a local implementation of the classic cd command
void AAShell::cd(CommandLine cl){
	if (chdir(cl.getArgVector(1)) == -1) {
		cout << "Directory not found." << endl;
	}
}