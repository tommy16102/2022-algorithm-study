/*******************************************************************
Algorithm Study
Baekjoon 22862 가장 긴 짝수 연속한 부분 수열 (large)
2023/04/15 이호준
# 아이디어
1. 투포인터
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int left = 0;
    int right = 0;

    vector<int> inputs(n, 0);
    for(int i = 0; i < n; i++){
        cin >> inputs[i];
    }

    int current_count = 0;
    int current_k = 0;
    int answer = 0;
    while(right < n){
        if(inputs[right] % 2 == 0){
            right++;
            current_count++;
            answer = max(answer, current_count);
        }else{
            if(current_k < k){
                current_k++;
                right++;
            }else{
                if(inputs[left] % 2 != 0){
                    left++;
                    current_k--;
                }else{
                    left++;
                    current_count--;
                }
            }
        }
    }

    cout << answer;

    return 0;
}