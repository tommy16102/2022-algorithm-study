/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT
2023/05/01 이호준
# 아이디어
1. Queue
2. 최대횟수 *3인 이유 q1의 마지막 원소 앞의 원소를 제외하고 모든 원소의 합이 같은 케이스
즉, 횟수만 고려하여 요약하면(휴리스틱) q1을 비우고 q1과 q2을 다시 q1으로 다 집어넣는 케이스가 모든 케이스이다.
*******************************************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    long long total_sum = 0;
    long long current_sum = 0;
    queue<int> q1, q2;
    for(auto a : queue1){
        total_sum += a;
        q1.push(a);
    }
    current_sum = total_sum;
    for(auto a : queue2){
        total_sum += a;
        q2.push(a);
    }
    long long goal_sum = total_sum / 2;
    
    int size = queue1.size();
    int current_move = 0;
    for(int i = 0; i < size * 3; i++){
        if(current_sum == goal_sum){
            return current_move;
        }else if (current_sum > goal_sum){
            int temp = q1.front(); q1.pop();
            q2.push(temp);
            current_sum -= temp;
        }else if (current_sum < goal_sum){
            int temp = q2.front(); q2.pop();
            q1.push(temp);
            current_sum += temp;
        }
        current_move++;
    }
    
    return -1;
}