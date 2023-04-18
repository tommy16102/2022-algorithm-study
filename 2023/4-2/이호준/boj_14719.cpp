/*******************************************************************
Algorithm Study
Baekjoon 14719 빗물
2023/04/18 이호준
# 아이디어
1. Stack -> 해결불가
2. 구현
*******************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    
    vector<int> block(w, 0);

    for(int i = 0; i < w; i++){
        cin >> block[i];
    }
    
    int answer = 0;
    
    for(int i = 1; i < block.size() - 1 ; i++){
        int left = *max_element(block.begin(), block.begin() + i);
        int right = *max_element(block.begin() + i + 1, block.end());
        int diff = min(left, right) - block[i];
        if(diff >= 0) 
            answer += diff;
    }
    
    cout << answer;
    return 0;
}