#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int v; int e; int start;
int INF = 123456789;
vector<pair<int, int>> map[20001]; // 벡터 배열
// map[x] = x과 연결되어 있는 친구들 목록(pair<인덱스, 가중치>로 표현됨)
int d[20001];

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e >> start;
    for (int i = 1; i <= e; i++) {
        int to; int from; int weight;
        cin >> from >> to >> weight;
        map[from].push_back(make_pair(to,weight));
        //map[to].push_back({ from,weight });
    }
    for (int i = 1; i <= v; i++) { // d의 초기값 INF로
        d[i] = INF;
    }
}

void solve() {
    priority_queue<pair<int, int>> pq; // pair<간선 비용, 인덱스> 로 가야 할 노드 목록

    // 시작점 초기화
    pq.push({ 0, start});
    d[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second; // 현재 검사중인 인덱스
        int cur_dis = -pq.top().first; // 인덱스가 가진 가중치, 인데 -로 들어가 있으므로 -1을 곱해서 양수로 만든다
        pq.pop();
        
        //만약 지금 꺼낸 것 보다 더 짧은 경로를 알고 있다면, 꺼낸것을 무시한다.
        if (d[cur] < cur_dis)
            continue;

        for (int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].first; // 인덱스
            int next_dis = cur_dis + map[cur][i].second; // 코스트
             
            if (next_dis < d[next]) { // 갱신할 때
                d[next] = next_dis;
                pq.push(make_pair(-next_dis, next)); // -로 넣는 이유는, 코스트가 작은 애를 위로 올라오게 하기 위함.
            }
        }

    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF)
            cout << "INF\n";
        else
        cout << d[i] << '\n';
    }

}


int main() {

    input();
    solve();
    return 0;
}