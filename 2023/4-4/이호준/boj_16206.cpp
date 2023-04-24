/*******************************************************************
Algorithm Study
Baekjoon 16206 롤케이크
2023/04/24 이호준
# 아이디어
1. 구현
*******************************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define ROLLCAKESIZE 10

using namespace std;

struct compare{
    bool operator()(int& operand, int& target){
        if(target % ROLLCAKESIZE == 0 && operand % ROLLCAKESIZE == 0)
            return target <= operand;
        else if (target % ROLLCAKESIZE == 0)
            return true;
        else if (operand % ROLLCAKESIZE == 0)
            return false;
        else
            return target <= operand;
    }
};

int answer = 0;

void getAllRollCake(priority_queue<int, vector<int>, compare> rollCakes){
    while(!rollCakes.empty()){
        if(rollCakes.top() == ROLLCAKESIZE){
            answer++;
            rollCakes.pop();
        }else{
            break;
        }
    }
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, compare> rollCakes;

    for(int i = 0 ; i < n; i++){
        int temp;
        cin >> temp;
        if(temp >= 10)
            rollCakes.push(temp);
    }

    int currentCuttingCount = 0;
    while(!rollCakes.empty()){
        int currentRollCakeSize = rollCakes.top();
        rollCakes.pop();

        if(currentRollCakeSize == ROLLCAKESIZE)
            answer++;
        else if (currentRollCakeSize == ROLLCAKESIZE * 2){
            currentCuttingCount++;
            answer += 2;
        }else{
            answer++;
            currentCuttingCount++;
            if(currentRollCakeSize - ROLLCAKESIZE >= ROLLCAKESIZE)
                rollCakes.push(currentRollCakeSize - ROLLCAKESIZE);
        }

        if(currentCuttingCount >= m)
            break;
    }

    getAllRollCake(rollCakes);

    cout << answer;

    return 0;
}
