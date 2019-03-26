/*
 * Prompt.h
 *
 *  Created on: Mar 26, 2019
 *      Author: ajv98
 */

#ifndef PROMPT_H_
#define PROMPT_H_

using namespace std;

#include <string>

class Prompt {
public:
	Prompt();
	string get() const;
private:
	string myCWD;
};

#endif /* PROMPT_H_ */
