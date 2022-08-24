#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int board[501][501];
bool v[501][501] = { false, };
int d[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> board[i][j];
            d[i][j] = -1;
        }
    }
}

int dfs(int x, int y) {
    if (d[x][y] == -1) {

        d[x][y] = 1; // 해당 칸에서 하루 먹고살수있다
        int t = 0; 

        for (int i = 0; i < 4; i++) { // 상하좌우
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && board[x][y] < board[nx][ny]) { // 조건 부합
                t = max(t, dfs(nx, ny)); // t = max(상,하,좌,우)
            }
        }
        d[x][y] += t; // 갈 수 있는 곳중에서 얻은 가장 큰 값을 더함
    }

    return d[x][y];
}

void dfs(pair<int, int> id, int depth, int x, int y) {

    d[id.first][id.second] = max(depth, d[id.first][id.second]);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int s = board[x][y];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && s < board[nx][ny] && v[nx][ny] == false) {
            v[nx][ny] = true;
            dfs(id, depth + 1, nx, ny);
            v[nx][ny] = false;
        }
    }

}


/*
1 3 1 2
3 2 3 4
2 1 4 1
3 4 1 2
*/


void solve() {

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans;
    
    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++) {
    //        dfs(make_pair(i, j), 1, i, j);
    //    }
    //}

    //int m = d[1][1];
    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++) {
    //        if (m < d[i][j])
    //            m = d[i][j];
    //        cout << d[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    ////cout << m;

}

int main() {
    input();
    solve();
    return 0;
}