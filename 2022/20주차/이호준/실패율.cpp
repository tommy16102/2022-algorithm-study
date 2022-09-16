/*******************************************************************
Algorithm Study
2019 Kakao Blind
실패율 level 1
2022/09/16 이호준
# 아이디어
1. 구현
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int stage_member[502];

double getfailPercentage(int n, int current_sum){
    if (stage_member[n] == 0)
        return 0;
    else
        return double(stage_member[n]) / current_sum;
}

bool compare(const pair<double,int> &a ,pair<double, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for (auto stage : stages){
        stage_member[stage]++;
    }
    
    vector<pair<double, int>> failures;
    
    int current_member = stage_member[N+1];
    
    for(int i = N; i > 0 ; i--){
        current_member += stage_member[i];
        failures.push_back({getfailPercentage(i, current_member), i});
    }
    
    sort(failures.begin(), failures.end(), compare);
    
    for(auto result : failures){
        answer.push_back(result.second);
    }
    
    return answer;
}