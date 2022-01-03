/*******************************************************************
Algorithm Study
Programmers 코딩테스트 고득점 Kit 2주차 (level 2 finish)
Stack/Queue / 다리를 지나는 트럭
2021/07/19 이호준
# 아이디어
1. pipeline처럼 맨 앞 트럭을 기준으로 다리에 올라갈 수 있는 최대 개수만큼 큐에 넣은 뒤
해당 작업을 1개로 보고 bridge_legth+size()로 구한다.
이때 하나가 나가고 들어오는 과정에서 새로운 작업단위와 그전단위의 관계를 식으로 나타내야하는데
실패하였다.

2. 문제 그대로 time으로 시간을 계속 지나가게 하고 문제조건을 만족하면 push, pop을 하면서
time을 축적해가면서 모든 트럭이 나갈때 까지 반복한다.

※ 해당 코드는 혜민이의 설명을 듣고 작성한 것으로 문제자체를 코드로 잘 녹여낸 것 같아서
이러한 방식을 통해 사고하는 방식을 늘려야겠다. 너무 어렵게 생각하는 경향이 있다.
*******************************************************************/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int bridge_weight = 0;
    int time = 0;
    int finish = 0;
    int truck_count = truck_weights.size();
    int current = 0;
    int next_truck_weight = 0;
    queue<int> bridge;
    queue<int> onBridgeTime;
    while (finish != truck_count)
    {
        time++;
        if (current != truck_count)
            next_truck_weight = truck_weights[current];
        if (time != 1 && time - onBridgeTime.front() == bridge_length)
        {
            bridge_weight -= bridge.front();
            bridge.pop();
            onBridgeTime.pop();
            finish++;
        }
        if (current != truck_count && bridge_weight + next_truck_weight <= weight && bridge.size() + 1 <= bridge_length)
        {
            bridge_weight += next_truck_weight;
            bridge.push(next_truck_weight);
            onBridgeTime.push(time);
            current++;
        }
    }
    answer += time;
    return answer;
}

int main(void)
{
    cout << solution(2, 10, {7, 4, 5, 6});
}
