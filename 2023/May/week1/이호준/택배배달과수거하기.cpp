/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT
2023/05/01 이호준
# 아이디어
1. 구현
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void moveTruck(vector<pair<int,int>>& waitingStack, int cap){
    int currentPickUp = 0;
    int lastDistance = 0;
    while(currentPickUp < cap){
        currentPickUp += waitingStack.back().second;
        lastDistance = waitingStack.back().first;
        waitingStack.pop_back();
        if(waitingStack.empty())
            break;
    }
    currentPickUp -= cap;
    if(currentPickUp > 0)
        waitingStack.push_back({lastDistance, currentPickUp});
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int moveDistance;

    vector<pair<int,int>> deliveryWaitingStack;
    vector<pair<int,int>> pickupWaitingStack;
    
    for(int i = 0; i < deliveries.size(); i++){
        if(deliveries[i] > 0)
            deliveryWaitingStack.push_back({i + 1, deliveries[i]});
        if(pickups[i] > 0)
            pickupWaitingStack.push_back({i + 1, pickups[i]});
    }
    
    while(1){
        
        if(deliveryWaitingStack.empty() && pickupWaitingStack.empty())
            break;
        
        if(deliveryWaitingStack.empty()){
            while(!pickupWaitingStack.empty()){
                moveDistance = pickupWaitingStack.back().first;
                answer += (moveDistance * 2);
                moveTruck(pickupWaitingStack, cap);
            }
        }else if (pickupWaitingStack.empty()){
            while(!deliveryWaitingStack.empty()){
                moveDistance = deliveryWaitingStack.back().first;
                answer += (moveDistance * 2);
                moveTruck(deliveryWaitingStack, cap);
            }
        }else{
            moveDistance = max(deliveryWaitingStack.back().first, pickupWaitingStack.back().first);
            answer += (moveDistance * 2);
            moveTruck(deliveryWaitingStack, cap);
            moveTruck(pickupWaitingStack, cap);
        }
    }
    
    return answer;
}