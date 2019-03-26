
#ifndef PATH_H_
#define PATH_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Path {
public:
	Path();
    string getDirectory (const int i) const;
    int find(const string& program) const;
private:
    vector<string> myDirectories;
};

#endif /* PATH_H_ */