/*
 * AAShell.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#include "AAShell.h"
#include "sys/wait.h"

AAShell::AAShell () {

}

void AAShell::run() {
	Path myPath;
	while (1) {
		Prompt myPrompt;
		cout <<  myPrompt.get() << "$ ";
		CommandLine myCommandLine (cin);
		char* command = myCommandLine.getCommand();
		string commandStr= string (command);

		int index= myPath.find (commandStr);
		if (commandStr == "cd") {
			//do cd
			cout << "Entered the cd branch" << endl;
		} else if (commandStr == "pwd") {
			//do pwd
			cout << "Entered the pwd branch" << endl;
			char array[1000];
			getcwd(array, 1000);
			cout << array << endl;
		} else if ( index >= 0 ) {
			//call system program
			cout << myPath.getDirectory(index) << endl;
			int pid= fork();
			if (pid == -1) {
				cerr << "Failed to create new child process" << endl;
				exit (2);
			} else if (pid == 0) {
				//child
				cout << "I am the child" << endl;
				string program= myPath.getDirectory(index) + "/" + commandStr;
				cout << program << endl;
				execve (program.c_str(), myCommandLine.getArgVector(), environ);
				cout << "Child had error in execve" << endl;
				exit(EXIT_SUCCESS);
			} else {
				//parent
				//put an if statement here based on noAmpersand
				cout << "I am the parent" << endl;
				waitpid(pid, NULL, 0);
			}
		} else {
			cout << "That is not a recognized command" << endl;
		}
	}
}
