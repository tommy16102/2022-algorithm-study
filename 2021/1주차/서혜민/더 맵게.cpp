#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

/*

2021.07.12 서혜민

priority_queue에 오름차순으로 scovile벡터에 있던 값들이 저장이 된다.
가장 좌측이 스코빌 지수가 가장 작은 수이고
그 오른쪽에 위치한 수가 두번째로 작은 수이다.
pop를 해주면서 이 값을 빼내고, 가장 작은 수에 두번째로 작은 수의 두배를 더해줘서
새롭게 만든 스코빌 지수를 priority_queue에 넣어준다.
이 과정을 반복을 하면서, 이 priority_queue의 크기가 1이면서 이 때의 값이 k보다 작으면 -1을 리턴하지만
그렇지 않고, 크기가 1이거나 가장 작은 수가 k이상이면 while문을 빠져나온다

*/

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0;i < scoville.size();i++) {
        pq.push(scoville[i]);
    }

    while (1) {
        if (pq.size() == 1 && pq.top() < K) return -1;
        if (pq.size() == 1) break;
        if (pq.top() >= K) break;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int res = first + (second * 2);
        pq.push(res);
        answer++;
    }
    return answer;
}

int main() {
    vector<int> a = { 1,2,3,9,10,12 };
    int n = 7;
    cout << solution(a, n);
}