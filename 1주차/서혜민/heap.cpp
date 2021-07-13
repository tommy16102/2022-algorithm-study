#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

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