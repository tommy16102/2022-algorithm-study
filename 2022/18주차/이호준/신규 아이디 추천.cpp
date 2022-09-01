#include <string>
#include <vector>

using namespace std;

string toLower(string id){
    for(auto &a : id){
        if (a >= 'A' && a <= 'Z'){
            a = a + 32;
        }
    }
    return id;
}

string removeStopWord(string id){
    string checked_string = "";
    for(auto a : id){
        if((a >= 'a' && a <= 'z') || (a >='0' && a <='9') || a =='-' || a =='_' || a=='.'){
            checked_string += a;
        }
    }
    return checked_string;
}

string removeStopChar(string id){
    string final_string = "";
    
    bool isSequence = false;
    for(auto a : id){
        if(a == '.'){
            isSequence = true;
        }else{
            if(isSequence){
                isSequence = false;
                final_string += ".";
            }
            final_string += a;
        }
    }
    
    if(final_string.size() > 0){
        if(final_string[0] == '.'){
            final_string = final_string.substr(1);
        }
        if(final_string.size() > 0){
            if(final_string[final_string.size()-1] == '.'){
                final_string = final_string.substr(0,final_string.size()-1);
            }
        }
    }
    return final_string;
}

string isEmpty(string id){
    if(id.size() == 0){
        return "a";
    }else{
        return id;
    }
}

string checkLength(string id){
    if(id.size() >= 16){
        if(id[14] == '.'){
            return id.substr(0, 14);
        }else{
            return id.substr(0, 15);
        }
    }else{
        return id;
    }
}

string addChar(string id){
    if(id.size() <= 2){
        char add_char = id[id.size()-1];
        while(id.size() != 3){
            id += add_char;
        }
    }
    return id;
}

string solution(string new_id) {
    string answer = "";
    return addChar(checkLength(isEmpty(removeStopChar(removeStopWord(toLower(new_id))))));
}