/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT
2023/05/01 이호준
# 아이디어
1. 구현 
### emoticons[current_event] * (1 - 0.1 * i)} =======> 오답
### emoticons[current_event] * (100 - 10 * i) / 100 (100으로 나중에 나눠야 정답)
-> 부동소수점 연산때문. 컴퓨터에서 0.1은 나타낼 수 없다...
*******************************************************************/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max_emoticonPlusUser = -1;
int max_Sales = -1;
vector<vector<int>> userInfo;

void getEventResult(vector<pair<int,int>> events){
    int current_emoticonPlusUser = 0;
    int current_sales = 0;
    for(vector<int> user : userInfo){
        int userRatioLimit = user[0];
        int userLimitPrice = user[1];
        int userTotalPrice = 0;
        bool emoticonPlusFlag = false;
        // {할인율, 할인가격}
        for(pair<int,int> event : events){
            if(userRatioLimit > event.first) continue;
            
            userTotalPrice += event.second;
            if(userTotalPrice >= userLimitPrice){
                emoticonPlusFlag = true;
                break;
            }
        }
        
        if(emoticonPlusFlag)
            current_emoticonPlusUser += 1;
        else
            current_sales += userTotalPrice;
    }
    
    if(current_emoticonPlusUser > max_emoticonPlusUser){
        max_emoticonPlusUser = current_emoticonPlusUser;
        max_Sales = current_sales;
    }else if (current_emoticonPlusUser == max_emoticonPlusUser){
        if(current_sales > max_Sales){
            max_Sales = current_sales;
        }
    }
}

void eventCombination(vector<pair<int,int>> event, vector<int> emoticons){
    if(event.size() == emoticons.size()){
        getEventResult(event);
        return;
    }
    
    int current_event = event.size();
    for(int i = 1; i <= 4; i++){
        event.push_back({ 10 * i , emoticons[current_event] * (100 - 10 * i) / 100});
        eventCombination(event, emoticons);
        event.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    userInfo = users;
    vector<pair<int,int>> event;
    
    eventCombination(event, emoticons);
    answer.push_back(max_emoticonPlusUser);
    answer.push_back(max_Sales);

    return answer;
}