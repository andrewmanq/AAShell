/*
 * AAShell.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98 and anq3
 */

#include "AAShell.h"
#include "sys/wait.h"

AAShell::AAShell () {

}

void AAShell::run() {
	Path myPath;
	
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
		} else if ( index >= 0 ) {
			//call system program
			cout << myPath.getDirectory(index) << endl;
			
			int pid= fork();
			if (pid == -1) {
				cerr << "Failed to create new child process" << endl;
				exit (2);

			} else if (pid == 0) {
				//child
				string program= myPath.getDirectory(index) + "/" + commandStr;
				try{
					execve (program.c_str(), myCommandLine.getArgVector(), environ);
				}catch(exception e){
					cout << "There was an issue executing this program, has it been installed correctly?" << endl;
				}
				exit(EXIT_SUCCESS);

			} else {
				//parent
				if(myCommandLine.noAmpersand()){
					waitpid(pid, NULL, 0);
				}
			}
		} else {
			cout << "That is not a recognized command" << endl;
		}
	}
}

void AAShell::pwd() {
	char array[1000];
	getcwd(array, 1000);
	cout << array << endl;
}

void AAShell::cd(CommandLine cl){
	chdir(cl.getArgVector(1));
}