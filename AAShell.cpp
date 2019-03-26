/*
 * AAShell.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#include "AAShell.h"

AAShell::AAShell () {
	char array [100];
	getcwd( array, 100);
	myCWD=string (array);
}

string AAShell::get() const {
	return myCWD;
}