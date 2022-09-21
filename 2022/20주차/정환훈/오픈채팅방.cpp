#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> inoutLog;
    vector<string> changeLog;
    vector<string> uidLog;    
    map<string, string> m;
        
    for(int i=0;i<record.size();i++){
        if(record[i][0] == 'E'){
            
            string s = record[i];
            
            int firstIndex = s.find(' ');
            s = s.substr(firstIndex+1);
            int secondIndex = s.find(' ');

            string uid = s.substr(0, secondIndex);
            string nickname = s.substr(secondIndex+1);
            uidLog.push_back(uid);
            m[uid] = nickname;
            inoutLog.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }
        else if(record[i][0] == 'L'){
            
            string s = record[i];
            int firstIndex = s.find(' ');
            s = s.substr(firstIndex+1);
            string uid = s;
            uidLog.push_back(uid);
            inoutLog.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
            
        }
        else{
            changeLog.push_back(record[i]);
            string s = record[i];
            int firstIndex = s.find(' ');
            s = s.substr(firstIndex+1);
            int secondIndex = s.find(' ');

            string uid = s.substr(0, secondIndex);
            string nickname = s.substr(secondIndex+1);      
            m[uid] = nickname;
        }
    }    

    for(int i=0;i<inoutLog.size();i++){
        answer.push_back(m[uidLog[i]] + inoutLog[i]);
    }
    
    return answer;
}
