#include "CommandLine.h"

using namespace std;

CommandLine::CommandLine (istream& in) {
    argc = 0;
    ampersand = false;
    string input;

    //take in a line of input from istream&
    getline(in, input);

    //istringstream splits the input into individual words
    istringstream ss(input);
    string word;
    vector<string> words = vector<string>();
    while(!ss.eof()){
        ss >> word;
        if(word != "&"){
            argc += 1;
            words.push_back(word);
        }else{
            ampersand = true;
        }
    }

    charVec = vector<char*>();

    for(int i = 0; i < words.size(); i++){
        charVec.push_back((char*)words[i].data());
    }

    argv = charVec.data();
}

//returns a pointer to the command portion of the command line (argv0)
char* CommandLine::getCommand() const{
    return argv[0];
}

// returns the number of command-line arguments on the command-line (i.e., argc). 
int CommandLine::getArgCount() const{
    return argc;
}

//returns a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv).
char ** CommandLine::getArgVector() const{
    return argv;
}

//returns a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]). 
char* CommandLine::getArgVector(int i) const{
    return argv[i];
}

//returns true if and only if no ampersand was given on the command-line 
bool CommandLine::noAmpersand() const{

    return !ampersand;
}