#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int n; int m; int start; int goal;
int INF = 123456789;
vector<pair<int, int>> map[1001]; // 벡터 배열
// map[x] = x과 연결되어 있는 친구들 목록(pair<인덱스, 가중치>로 표현됨)
int d[1001];

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from; int to; int weight;
        cin >> from >> to >> weight;
        map[from].push_back(make_pair(to, weight));
    }

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    cin >> start >> goal;
}

void solve() {
    priority_queue<pair<int, int>> pq; // pair<간선 비용, 인덱스> 로 가야 할 노드 목록
    // pair<인덱스, 간선 비용> 으로 할 시에 sort가 이상하게 되는 건지 시간 초과 됨
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

    cout << d[goal];

}


int main() {

    input();
    solve();
    return 0;
}