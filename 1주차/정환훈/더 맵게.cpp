#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : priority_queue(최소 힙)을 사용한다.
    숫자 두개를 뺄 수 있으면 가장 작은 수와 두번째로 작은 수를 사용하여 다음 수를 구한다.
    배열이 빌 때까지 반복

*/

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < scoville.size(); i++) {
        q.push(scoville[i]);
    }
    int answer = 0;
    int i = 0;
    int flag = 0;
    while (q.top() < K) {

        int temp1 = q.top();
        q.pop();

        if (q.empty()) {
            flag = 1;
            break;
        }
        int temp2 = q.top();
        q.pop();

        int temp = temp1 + temp2 * 2;
        q.push(temp);
        answer++;

    }

    if (flag == 1) return -1;
    return answer;

}