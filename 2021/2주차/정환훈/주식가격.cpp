#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/16
    
    기본 아이디어 : 그냥 2중포문 돌면서 센다
*/

vector<int> solution(vector<int> prices) {
    
    
    
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++) {

        int price = prices[i];
        int k = 0;

        for (int j = i + 1; j < prices.size(); j++) {
            if (price <= prices[j]) {
                k++;
            }
            else {
                answer.push_back(k);
                break;
            }
            if (j == prices.size() - 1) {
                answer.push_back(k);
            }

        }

    }

    answer.push_back(0);

    return answer;
}