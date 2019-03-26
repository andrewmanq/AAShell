
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
