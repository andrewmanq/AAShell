#include "CommandLine.h"

CommandLine::CommandLine (istream& in) {
    string input;
    getline(in, input);

    istringstream ss(input);

    string word;
    *argc = 0;
    vector<string> words = vector<string>();
    while(!ss.eof()){
        *argc += 1;
        ss >> word;
        words.push_back(word);
        //cout << word << "\n";
    }
    
}