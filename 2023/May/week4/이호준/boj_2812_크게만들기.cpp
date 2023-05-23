/*******************************************************************
Algorithm Study
Baekjoon 2812 크게 만들기
2023/05/23 이호준
# 아이디어
1. Stack
*******************************************************************/

#include <iostream>
#include <stack>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    string inputs;
    cin >> inputs;
    
    stack<char> s;
    int outCount = 0;
    for(int i = 0; i < n; ++i){
        while(!s.empty() && s.top() < inputs[i] && outCount < k){
            s.pop();
            outCount++;
        }
        s.push(inputs[i]);
    }

    while(outCount < k){
        outCount++;
        s.pop();
    }

    stack<char> answer;
    while(!s.empty()){
        answer.push(s.top());
        s.pop();
    }
    while(!answer.empty()){
        cout << answer.top();
        answer.pop();
    }

    return 0;
}