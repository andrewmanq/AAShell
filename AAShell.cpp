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
	while (1) {
		Prompt myPrompt;
		cout <<  myPrompt.get() << "$ ";
		CommandLine myCommandLine (cin);
		char* command = myCommandLine.getCommand();

		// char** test = myCommandLine.getArgVector();
		// for(test; !test; test++){
		// 	cout << test << endl;
		// }

		int index= myPath.find (command);
		if (command == "cd") {
			//do cd
		} else if (command == "pwd") {
			//do pwd
		} else if ( index >= 0 ) {
			//call system program
			cout << myPath.getDirectory(index) << endl;
			int pid= fork();
			if (pid == -1) {
				//failure
			} else if (pid == 0) {
				//child

			} else {
				//parent
			}
		} else {
			cout << "That is not a recognized command" << endl;
		}
	}
}
