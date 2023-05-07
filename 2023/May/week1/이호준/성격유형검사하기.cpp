/*******************************************************************
Algorithm Study
2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
2023/05/04 이호준
# 아이디어
1. MAP을 이용한 구현
*******************************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct SURVEY_INFO{
    int num;
    bool reverse;
};

void updateScore(int score[4], SURVEY_INFO info, int choice){
    int currentScore = 4 - choice;
    if(info.reverse)
        currentScore = -currentScore;
    score[info.num] += currentScore;
}

void updateAnswer(string &answer, int score[4]){
    if(score[0] >= 0)
        answer += "R";
    else
        answer += "T";
    if(score[1] >= 0)
        answer += "C";
    else
        answer += "F";
    if(score[2] >= 0)
        answer += "J";
    else
        answer += "M";
    if(score[3] >= 0)
        answer += "A";
    else
        answer += "N";
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<string, SURVEY_INFO> surveyQuery;
    surveyQuery["RT"] = {0, false}; surveyQuery["TR"] = {0, true};
    surveyQuery["CF"] = {1, false}; surveyQuery["FC"] = {1, true};
    surveyQuery["JM"] = {2, false}; surveyQuery["MJ"] = {2, true};
    surveyQuery["AN"] = {3, false}; surveyQuery["NA"] = {3, true};
    
    int kmbtiScore[4] = {0, 0, 0, 0};
    
    for(int i = 0; i < survey.size(); i++){
        SURVEY_INFO currentSurveyInfo = surveyQuery[survey[i]];
        updateScore(kmbtiScore, currentSurveyInfo, choices[i]);
    }
    
    updateAnswer(answer, kmbtiScore);
    
    return answer;
}