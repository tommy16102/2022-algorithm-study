/*******************************************************************
Algorithm Study
Baekjoon 9주차 다익스트라/이분탐색
1261 알고스팟
2021/09/10 이호준
# 아이디어
1. 다익스트라 알고리즘을 어떻게 적용시키는 문제였다.
다음 위치 지점에 도달하기 까지 몇개의 벽을 부셔야하는지를 기록한다면 문제를 해결할 수 있었다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define INF 2100000000
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int answer[101][101];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> m >> n;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = temp[j] - '0';
            answer[i][j] = INF;
        }
    }

    queue<pair<int, int>> q;

    q.push({0, 0});
    answer[0][0] = 0;

    while (!q.empty())
    {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (map[nx][ny] == 1)
            {
                if (answer[nx][ny] > answer[x][y] + 1)
                {
                    answer[nx][ny] = answer[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            else if (map[nx][ny] == 0)
            {
                if (answer[nx][ny] > answer[x][y])
                {
                    answer[nx][ny] = answer[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << answer[n - 1][m - 1];

    return 0;
}