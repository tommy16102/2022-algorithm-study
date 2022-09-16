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
        // cout << command << " " << user_id << " " << nick_name <<"\n";
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