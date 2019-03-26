
#include "Prompt.h"
#include <unistd.h>

Prompt::Prompt () {
	char array[1000];
	getcwd(array, 1000);
	myCWD=string (array);
}

string Prompt::get() const {
	return myCWD;
}
