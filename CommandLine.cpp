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

    charVec = vector<char*>();

    for(int i = 0; i < words.size(); i++){
        charVec.push_back((char*)words[i].data());
    }

    argv = charVec.data();
}

char* CommandLine::getCommand() const{
    // answer = argv[0].c_str();
    return argv[0];
}

int CommandLine::getArgCount() const{
    return argc;
}

char ** CommandLine::getArgVector() const{
    return argv;
}

string CommandLine::getArgVector(int i) const{
    return argv[i];
}

bool CommandLine::noAmpersand() const{

    // for(int i = 0; i < argc; i++){
    //     if(argv[i] == '&'){
    //         return false;
    //     }
    // }
    return true;
}