#include "CommandLine.h"

using namespace std;

CommandLine::CommandLine (istream& in) {
    string input;
    getline(in, input);

    istringstream ss(input);

    string word;
    argc = 0;
    vector<string> words = vector<string>();
    while(!ss.eof()){
        argc += 1;
        ss >> word;
        words.push_back(word);
    }

    argv = words;
}

string CommandLine::getCommand() const{
    return argv[0];
}

int CommandLine::getArgCount() const{
    return argc;
}

vector<string> CommandLine::getArgVector() const{
    return argv;
}

string CommandLine::getArgVector(int i) const{
    return argv[i];
}

bool CommandLine::noAmpersand() const{

    for(int i = 0; i < argc; i++){
        if(argv[i] == "&"){
            return false;
        }
    }
    return true;
}