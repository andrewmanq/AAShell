/*
 * Prompt.h
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#ifndef AASHELL_H_
#define AASHELL_H_

using namespace std;

#include <string>

class AAShell {
public:
	AAShell();
	string get() const;
private:
	string myCWD;
};

#endif /* AASHELL_H_ */