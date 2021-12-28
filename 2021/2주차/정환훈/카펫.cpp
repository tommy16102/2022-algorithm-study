#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/15
    
    기본 아이디어 : brown = 2가로*2세로+4, yellow = 가로*세로
    여기서 가로, 세로는 yellow의 약수들 중에서 골라짐
    그래서 이걸 노가다로 구함
    근데 yellow가 제곱수인 경우에는 좀 다름
    그래서 yellow가 제곱수인 경우에만 다르게 처리해줘서 제곱근+2, 제곱근+2 반환

*/

vector<int> divisor(int num) {

    vector<int> divis;
    
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divis.push_back(i);
        }
    }

    return divis;

}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    vector<int> divis = divisor(yellow);


    int d1 = 0; int d2 = 0;
    
    int test = sqrt(yellow);

    if (test * test == yellow && brown == 4 * test + 4) {

        return { test + 2, test + 2 };
    }


    for (int i = 0; i < divis.size(); i++) {

        for (int j = i+1; j < divis.size(); j++) {
            d1 = divis[i]; d2 = divis[j];

            if (2 * d1 + 2 * d2 + 4 == brown && d1 * d2 == yellow) {

                if (d1 > d2) {
                    answer.push_back(d1 + 2);
                    answer.push_back(d2 + 2);
                }
                else {
                    answer.push_back(d2 + 2);
                    answer.push_back(d1 + 2);
                }
                break;
            }
        }
    }
    return answer;
}