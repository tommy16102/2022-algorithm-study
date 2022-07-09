/*******************************************************************
Algorithm Study
프로그래머스 2018 KAKAO BLIND RECRUITMENT 
[1차] 다트 게임
2022/07/09 이호준
# 아이디어
1. 문자열 파싱과 구현 -> 코드를 추후 개선 시켜야한다.
*******************************************************************/
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

typedef struct DART{
    int score;
    int bonus = 1;
};

bool isDigit(char a){
    if(a >= '0' && a <= '9'){
        return true;
    }else{
        return false;
    }
}

int applyBonus(char a, int score){
    if(a == 'T'){
        return score * score * score;
    }else if (a == 'D'){
        return score * score;
    }else {
        return score;
    }
}

bool isOption(char a){
    if(a == '*' || a == '#'){
        return true;
    }else{
        return false;
    }
}

int getScore(vector<DART> dart){
    int score = 0;
    for(auto a : dart){
        score +=(a.score * a.bonus);
    }
    return score;
}

int solution(string dartResult) {
    int answer = 0;
    vector<DART> dart;
    int current_dart = 0;
    for(int i = 0; i < 3; i++){
        int current_score;
        int bonus = 1;
        if(isdigit(dartResult[current_dart])){
            if(isdigit(dartResult[current_dart+1])){
                current_score = stoi(dartResult.substr(current_dart,2));
                current_dart++;
            }else{
                current_score = dartResult[current_dart] - '0';
            }
            current_dart++;
        }
        current_score = applyBonus(dartResult[current_dart++], current_score);
        if(isOption(dartResult[current_dart])){
                if(dartResult[current_dart] == '*'){
                    if(i >= 1){
                        dart[i - 1].bonus *= 2;
                    }
                    bonus *= 2;
                }else{
                    bonus *= -1;   
                }
                current_dart++;
        }
        dart.push_back({current_score, bonus});
        current_score = 0;
        bonus = 1;
    }
    
    return getScore(dart);
}