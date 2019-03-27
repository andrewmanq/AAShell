/*
 * main.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */


// #include "Prompt.cpp"
// #include "Path.cpp"
#include "AAShell.cpp"
#include <iostream>

using namespace std; 

int main () {
	CommandLine cl = CommandLine(cin);
	cout << cl.argc;
	cout << cl.argv[0];

	AAShell myShell;
	myShell.run();
}




