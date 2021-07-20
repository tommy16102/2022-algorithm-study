#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/15

    기본 아이디어 : 그냥 h_index가 가능한지 0부터 차근차근 해본다...

*/

int solution(vector<int> citations) {
    int answer = 0;

    
    int h_test = 0;
    int h_index = 0;

    int num = 0;


    while (h_test == 0) {

        num = 0;
        for (int i = 0; i < citations.size(); i++) {

            h_test = 1;

            if (h_index <= citations[i]) {
                num++;
            }

            if (h_index <= num) {
                h_index++;
                h_test = 0;
                break;
            }

        }
    }
    answer = h_index - 1;

    return answer;
}