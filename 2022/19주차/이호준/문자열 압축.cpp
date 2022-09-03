/*******************************************************************
Algorithm Study
2020 Kakao Blind
문자열 압축 level 2
2022/09/02 이호준
# 아이디어
1. 1부터 나눌 수 있는 최대 수인 문자열 길이 /2 까지 모두 확인하여 최소값 구하기
*******************************************************************/
#include <algorithm>
#include <string>

using namespace std;

int solution(string s) {
    int ssize = s.size();
    int answer = s.size();
    for (int i = 1; i <= (ssize / 2); i++) {

        string matchString = s.substr(0, i);
        int matchCnt = 1;
        string res = "";
        for (int j = i; j < ssize; j += i) {
            if (matchString == s.substr(j, i))  matchCnt++;
            else {
                if (matchCnt > 1) res += to_string(matchCnt);
                
                res += matchString;
                matchString = s.substr(j, i);
                matchCnt = 1;
            }
        }
        if(matchCnt > 1) res += to_string(matchCnt);
        res += matchString;
        answer = min(answer, (int)res.size());

    }
     
    return answer;
}