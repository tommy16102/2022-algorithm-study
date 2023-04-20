/*******************************************************************
Algorithm Study
Baekjoon 1253 좋다
2023/04/14 이호준
# 아이디어
1. 투 포인터 알고리즘
    - 고려해야할 지점이 많았던 문제다.
    - 투 포인터를 진행할 때 자기 자신을 사용하는 경우를 체크해야한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, answer = 0;

    cin >> n;

    if(n < 3){
        cout << answer;
        return 0;
    }

    vector<int> inputs(n, 0);
    unordered_map<int, bool> numbers;

    for(int i = 0; i < n; i++){
        cin >> inputs[i];
    }

    
    sort(inputs.begin(), inputs.end());
    
    int left = 0;
    for(int i = 0; i < inputs.size(); i++){
        int right = inputs.size() - 1;
        left = 0;

        while(left < right){
            if(inputs[left] + inputs[right] == inputs[i]){
                if(left == i){
                    left++;
                }else if (right == i){
                    right--;
                }else{
                    answer++;
                    break;
                }
            }else if(inputs[left] + inputs[right] > inputs[i]){
                right--;
            }else{
                left++;
            }
        }
    }

    cout << answer;

    return 0;
}