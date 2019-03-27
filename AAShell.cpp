/*
 * AAShell.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#include "AAShell.h"

AAShell::AAShell () {

}

void AAShell::run() {
	Path myPath;
	string program;
	while (1) {
		Prompt myPrompt;
		cout <<  myPrompt.get() << "$ ";
		CommandLine myCommandLine (cin);
		//char * command = myCommandLine.getCommand();
		string command = "ls";
		int index= myPath.find (command);
		if (command == "cd") {
			//do cd
		} else if (command == "pwd") {
			//do pwd
		} else if ( index >= 0 ) {
			//call system program
			cout << myPath.getDirectory(index) << endl;
		} else {
			cout << "That is not a recognized command" << endl;
		}
	}
}
