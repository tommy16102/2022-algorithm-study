/*******************************************************************
Algorithm Study
Baekjoon 1700 멀티탭 스케줄링
2023/04/20 이호준
# 아이디어
1. Greedy
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define EMPTY 0

using namespace std;

int multiTap[101];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> waiting_queue(k, 0);

    for(int i = 0; i < k; i++){
        cin >> waiting_queue[i];
    }

    int swapCount = 0;
    for(int electronics = 0; electronics < k; electronics++){

        // 사용중이라면
        bool isInUse = false;
        for(int i = 0; i < n; i++){
            if(multiTap[i] == waiting_queue[electronics]){
                isInUse = true;
                break;
            }
        }

        if(isInUse)
            continue;
        
        // 빈공간이 존재한다면
        for(int i = 0; i < n; i++){
            if(multiTap[i] == EMPTY){
                multiTap[i] = waiting_queue[electronics];
                isInUse = true;
                break;
            }
        }
        
        if(isInUse)
            continue;

        // 앞으로 사용되지 않거나, 가장 나중에 사용될 제품 찾기
        int plug = -1, waitingTime = -1;
        for(int i = 0; i < n; i++){
            bool willBeUsed = false;
            for(int j = electronics + 1; j < k; j++){
                if(multiTap[i] == waiting_queue[j]){
                    if(waitingTime < j){
                        plug = i;
                        waitingTime = j;
                    }
                    willBeUsed = true;
                    break;
                }
            }
            if(!willBeUsed){
                plug = i;
                break;
            }
        }
        
        multiTap[plug] = waiting_queue[electronics];
        swapCount++;
    }

    cout << swapCount;

    return 0;
}