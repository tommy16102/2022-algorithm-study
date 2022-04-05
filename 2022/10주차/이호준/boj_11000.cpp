/*******************************************************************
Algorithm Study
Baekjoon OJ Greedy
11000 강의실 배정
2022/04/04 이호준
# 아이디어
1. 강의실 배정문제.
문제그 자체로 강의실을 스케쥴링 하는 문제이다.
priority_queue를 이용해서 강의실을 오름 차순으로 정렬하고 넣어준다.
가장 빨리 끝나는 강의를 큐로 확인하고 해당 강의 보다 먼저시작하면 강의실을 늘리는 방식으로 진행하여
마지막의 큐에 쌓인 사이즈가 필요한 강의실 수가 된다.
*******************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;

pair<int,int> works[200001];

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.first==b.first) {
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> works[i].first >> works[i].second;
    }
    sort(works, works+n, compare);

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(works[0].second);
    for(int i=1 ; i<n ; i++) {
        int start = works[i].first;
        int end = works[i].second;
        int now = q.top();
        if(now > start) {
            q.push(end);
        } else {
            q.pop();
            q.push(end);
        }
    }
    cout << q.size();
    return 0;
}