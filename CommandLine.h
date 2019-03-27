
#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
#include <bits/stdc++.h>

class CommandLine {
public:
	int argc;
	std::vector<string> argv;
	CommandLine(istream& in);
private:

};

#endif