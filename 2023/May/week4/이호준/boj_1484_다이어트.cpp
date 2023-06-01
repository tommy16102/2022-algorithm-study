/*******************************************************************
Algorithm Study
Baekjoon 1484 다이어트
2023/05/25 이호준
# 아이디어
1. 투포인터
*******************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int g;
    cin >> g;

    int left = 1;
    int right = 2;
    int answer = 0;
    while(left < right){
        int current_g = right * right - left * left;
        if(current_g == g){
            cout << right << "\n";
            answer++;
            right++;
        }else if (current_g > g){
            left++;
        }else{
            right++;
        }
    }  

    if(answer == 0)
        cout << -1; 

    return 0;
}