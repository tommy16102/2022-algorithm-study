#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*

2021.07.19 서혜민

answer : 소요 시간
weightSum : 다리 위 트럭의 무게 합
pass : 다리를 지나간 트럭의 수

onBridge다리를 건너는 트럭의 무게와과 다리를 건너는 데 소요되고 있는 시간을 가지는 벡터이다. 
벡터에 삽입된 트럭의 무게의 합과 현재 다리를 건너려는 트럭의 무게,  그리고
현재 벡터의 길이, 즉 다리를 건너는 트럭의 수를 입력 받은 정해진 무게, 트럭의 수와 비교하여
해당 트럭이 다리를 건널 수 있다면 onBridge벡터에 트럭의 무게와 처음으로 소요되는 시간 1초를 삽입을 해주면서,weightSum도 갱신을 해준다.
이때 1초마다 트럭은 다리의 길이 중 1을 가며, 또한 트럭이 다리에 들어설수 있을 지 정해지므로, 계속 다리 위의 트럭의 다리를 건너는 데 소요되는 시간을 1초씩 더해준다.
그리고 다리에서 가장 맨 앞에 위치한 트럭의 소요시간이 다리의 길이와 같아지면 다리를 완전히 건너게 되므로, 이를 벡터에서 빼주면서 weightSum을 새롭게 갱신한다.

이 과정을 모든 트럭이 다리를 건널 때까지 반복해준다.

*/
int solution(int bridge_length, int weight, vector<int> v) {
    int answer = 0;
    int weightSum = 0;
    int pass = 0;
    vector<pair<int,int>> onBridge;

    int index = 0;
    while (pass<v.size()) {
        answer++;//초.
        if (onBridge.size() + 1 <= bridge_length && weightSum + v[index] <= weight) {
            onBridge.push_back({ v[index],1 });
            weightSum += v[index++];
        }
        if (onBridge[0].second >= bridge_length) {
            weightSum -= onBridge[0].first;
            onBridge.erase(onBridge.begin());
            pass++;
        }
        for (int i = 0;i < onBridge.size();i++) {
            onBridge[i].second++;
        }
        cout << index << " " << answer << endl;
    }
    return answer+1;
}

int main() {
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });
}