/*
 * Prompt.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#include "Prompt.h"

Prompt::Prompt () {
	myCWD="Hello World";
}

string Prompt::get() const {
	return myCWD;
}
