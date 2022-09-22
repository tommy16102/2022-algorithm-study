/*******************************************************************
Algorithm Study
2019 Kakao Blind
오픈채팅방 level 2
2022/09/16 이호준
# 아이디어
1. map을 이용한 구현
*******************************************************************/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, string> users;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<vector<string>> parsing_result;
    
    for(string input : record){
        int first_blank = input.find(' ');
        int last_blank = input.rfind(' ');
        string command = input.substr(0, first_blank);
        string user_id = input.substr(first_blank + 1, last_blank - first_blank - 1);
        string nick_name = input.substr(last_blank+1);
        if (command == "Enter" || command == "Change"){
            users[user_id] = nick_name;
        }
        if (command == "Enter" || command == "Leave"){
            parsing_result.push_back(vector<string>{command, user_id});
        }
    }
    
    for(auto command : parsing_result){
        string temp = "";
        temp += users[command[1]];
        if(command[0] == "Enter"){            
            temp += "님이 들어왔습니다.";
        }else{
            temp += "님이 나갔습니다.";
        }
        answer.push_back(temp);
    }
    
    return answer;
}