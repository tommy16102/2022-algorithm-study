#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    
    
    for(int i=0;i<new_id.size();i++){
        new_id[i] = tolower(new_id[i]);
    }
    

    for(int i=0;i<new_id.size();i++){        
        if(!(isalpha(new_id[i]) || isdigit(new_id[i]) 
             || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
        else{
        }
    }
    

    
    for(int i=0;i<new_id.size();i++){
        if(i < new_id.size() && new_id[i] == '.' && new_id[i+1] == '.'){
            new_id.erase(new_id.begin() + i+1);
            i--;
        }
    }
    
    if(new_id.front() == '.')
        new_id.erase(new_id.begin());
    
    if(new_id.back() == '.')
        new_id.pop_back();
    
    if(new_id == "")
        new_id = "a";
    
    if(new_id.size() >= 16)
        new_id = new_id.substr(0, 15);
    
    if(new_id.back() == '.')
        new_id.pop_back();
    
    if(new_id.size() <= 2)
        new_id += new_id.back();
    if(new_id.size() <= 2)
     new_id += new_id.back();
    if(new_id.size() <= 2)
        new_id += new_id.back();

    
    string answer = new_id;
    return answer;
}