/*******************************************************************
Algorithm Study
Baekjoon OJ Stack
17298 오큰 수
2022/04/08 이호준
# 아이디어
1. 스택을 이용한다.
뒤에서 부터 체킹.

*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> input(n, 0);
    vector<int> stack;
    vector<int> answer(n,0);
    for(int i =0 ;i <n ;i++){
        cin >> input[i];
    }

    for(int i = n-1 ; i>=0; i--){
        while(!stack.empty() && stack.back() <= input[i])
            stack.pop_back();
        if(stack.empty()) answer[i] = -1;
        else answer[i] = stack.back();

        stack.push_back(input[i]);
    }  

    for(auto a : answer)
        cout << a << " ";

    return 0;
}