/*
 * Prompt.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#include "Prompt.h"

Prompt::Prompt () {
	char array [100];
	getcwd( array, 100);
	myCWD=string (array);
}

string Prompt::get() const {
	return myCWD;
}
