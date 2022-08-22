#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

//step 1
string upperToLower(string new_id) {
    for (char &c : new_id) c = tolower(c);
    return new_id;
}

//step 2
string removeCharacter(string new_id) {
    string new_new_id = "";
    for (int i = 0; i < new_id.length(); i++) {
        char c = new_id[i];
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.') new_new_id += c;
    }
    return new_new_id;
}

//step 3, 4
string removePoint(string new_id) {
    string new_new_id = "";
    bool isPoint = false;
    for (int i = 0; i < new_id.length(); i++) {
        char c = new_id[i];
        if (c != '.') {
            new_new_id += c;
            isPoint = false;
        }
        else if (c == '.' && !isPoint) {
            new_new_id += c;
            isPoint = true;
        }
    }    
    if (new_new_id[new_new_id.length() - 1] == '.') new_new_id = new_new_id.substr(0, new_new_id.length() - 1);
    if (new_new_id[0] == '.') new_new_id = new_new_id.substr(1);
    return new_new_id;
}

//step 5
string makeEmptyA(string new_id) {
    if (new_id.length() == 0) new_id = "a";
    return new_id;
}

//step 6
string removeMoreThan15(string new_id) {
    new_id = new_id.substr(0, 15);
    if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    return new_id;
}

//step 7
string pushLessThan2(string new_id) {
    cout<<"7 "<<new_id<<endl;
    while(new_id.length() < 3) {
        new_id += new_id[new_id.length() - 1];
    }
    return new_id;
}

string solution(string new_id) {
    return pushLessThan2(removeMoreThan15(makeEmptyA(removePoint(removeCharacter(upperToLower(new_id))))));
}

