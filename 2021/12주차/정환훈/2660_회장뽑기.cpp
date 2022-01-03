#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<int> lists[51]; // 노드 i와 연결되어 있는 노드 목록
int scores[51]; // 노드 i의 점수
void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (true) {
        int from; int to;
        cin >> from >> to;
        if (from == -1 && to == -1) // 종료조건
            break;
        lists[from].push_back(to); // 간선 연결
        lists[to].push_back(from); // 간선 연결

    }

}

void bfs(int start) {
    int v[51] = { 0, };
    queue<int> q;
    q.push(start);
    v[start] = 1; // 출발
    while (!q.empty()) { // bfs
        int now_node = q.front(); // 현재 노드
        q.pop();
        vector<int> next_lists = lists[now_node]; // 다음 갈 노드들 리스트
        for (int i = 0; i < next_lists.size(); i++) { // 각각의 노드를 방문해보는데
            int next_node = next_lists[i]; // 간 노드가
            if (v[next_node] == 0) { // 처음 밟은 노드일때만
                q.push(next_lists[i]); // 해당 노드에서 bfs 진행
                v[next_node] = v[now_node] + 1; // 지금까지 온 level에 +1 해서 저장
            }
        }
    }
    
    int max = 0; // 이제 가장 오래 걸린 level 찾을거야
    for (int i = 0; i < 51; i++) {
        if (max < v[i])
            max = v[i];
    }

    scores[start] = max - 1; // 1로 시작했으니 1 빼기
}


void solve() {

    for (int i = 1; i <= n; i++) { // 모든 노드의 점수 구하기
        bfs(i);
    }

    int min_v = 999; // 가장 작은 값 찾기
    for (int i = 1; i <= n; i++) {
        if (min_v > scores[i])
            min_v = scores[i];
    }
    vector<int> results;
    for (int i = 1; i <= n; i++) {
        if (min_v == scores[i]) {
            results.push_back(i);
        }
    }

    cout << min_v << " " << results.size() << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i != results.size() - 1) cout << " ";
    }

}


int main() {
    input();
    solve();
    return 0;
}