/*******************************************************************
Algorithm Study
BAEKJOON 21주차
1034 램프
2022/10/04 이호준
# 아이디어
1. 완전탐색
*******************************************************************/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){   
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int height, width;
    int ans = -1;
    string arr[50];

    cin >> height >> width;

    for (int y = 0; y < height; y++){
        cin >> arr[y];
    }

    int k;
    cin >> k;

    for (int i = 0; i < height; i++){
        int zeroCount = 0;
        for (int h = 0; h < width; h++){
            if (arr[i][h] == '0'){
                zeroCount++;
            }
        }
        int sum = 0;
        if (zeroCount <= k && zeroCount % 2 == k % 2){
            for (int y = 0; y < height; y++){
                if (arr[i] == arr[y]){
                    sum++;
                }
            }
        }
        ans = max(sum, ans);
    }
    cout << ans;
    return 0;
}