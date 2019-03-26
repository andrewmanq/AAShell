
#include "Path.h"
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

Path::Path () {
	char * ptr;
    ptr= getenv ("PATH");
    string entry="";
    for (char* charPtr= ptr; *charPtr; charPtr++) {
        if (*charPtr == ':') {
            myDirectories.push_back (entry);
            entry="";
        } else {
            entry=entry + *charPtr;
        }
    }
    // for (unsigned i=0; i<myDirectories.size(); i++) {
    //     cout << myDirectories[i] << endl;
    // }
}

string Path::getDirectory (const int i) const {
    return myDirectories [i];
}

int Path::find(const string& program) const {
    int index=-1;
    for (unsigned i=0; i<myDirectories.size(); i++) {
        DIR* dirPtr=opendir (myDirectories[i].c_str());
        if (!dirPtr) {
            continue;
        }
        struct dirent * entryPtr;
        while ((entryPtr=readdir(dirPtr)) != NULL) {
            if (entryPtr->d_name == program) {
                index=i;
                return index;
            }
        }
    }
    return index;  
}
