#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210909
int n; int m;
char map[101][101];
int d[101][101];
int INF = 987654321;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            map[i][j] = 'x';
            d[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }


}

void solve() {
    

    priority_queue<pair<int, pair<int, int>>> pq; // 코스트, (x, y)
    // 출발 시점
    pq.push(make_pair(0, make_pair(1, 1)));
    d[1][1] = 0;

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cur_cost = -pq.top().first; // 현재 비용
        pq.pop();

        if (cur_cost < d[x][y]) // 갱신이 필요 없음
            continue;

        for (int i = 0; i < 4; i++) { // 4가지 bfs
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;

            pair<int, int> next = make_pair(nx, ny);
            int next_cost = cur_cost;
            if (map[nx][ny] == '1') // 1일 시에만 cost 추가
                next_cost++;
            if (d[nx][ny] > next_cost) { // 갱신 가능 시 갱신
                d[nx][ny] = next_cost;
                pq.push(make_pair(-next_cost, next)); // 다음 조사 노드
            }

        }

    }


    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= m; j++) {
    //        cout << d[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout <<  d[n][m];

}


int main() {

    input();
    solve();
    return 0;
}