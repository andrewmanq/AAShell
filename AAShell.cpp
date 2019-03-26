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
	Prompt myPrompt;
	cout <<  myPrompt.get() << "$ ";
	string program;
	while (1) {
		cin >> program;
		int index= myPath.find (program);
		if (index >= 0) {
			cout << myPath.getDirectory(index) << endl;
		} else {
			cout << "Program doesn't exist." << endl;
		}
	}
}
