/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT
2023/05/01 이호준
# 아이디어
1. 구현
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define DAY 28
#define MONTH 12

using namespace std;

int convertToDays(string target){
    int year = stoi(target.substr(0, 4));
    int month = stoi(target.substr(5, 2));
    int day = stoi(target.substr(8));
    return year * MONTH * DAY + month * DAY + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> privacyLimits;
    for(string term : terms){
        char type = term[0];
        int month = stoi(term.substr(2));
        privacyLimits.insert({type, month * DAY});
    }
    
    int todayInt = convertToDays(today);
    
    for(int i = 0; i < privacies.size(); i++){
        string privacy_day = privacies[i].substr(0, 10);
        char privacy_type = privacies[i][11];
        int privacyDayInt = convertToDays(privacy_day);
        int privacyDayLimitOffset = privacyLimits[privacy_type];
        if(todayInt >= privacyDayInt + privacyDayLimitOffset){
            answer.push_back({i + 1});
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}