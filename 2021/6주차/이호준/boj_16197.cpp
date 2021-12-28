/*******************************************************************
Algorithm Study
Baekjoon 6주차
16197 두 동전
2021/08/14 이호준
# 아이디어
1. 문제가 요구하는대로 최선거리를 찾기위해 bfs를 시도한다.
이떄 종료조건은 한개의 동전만이 graph에서 벗어나는 경우(즉 배열의 인덱스를 허용 벗어날 때)
이때 방문헀던곳을 다시 방문하지 않도록 하기위해서 4차원 배열을 이용한다. 즉 2개의 동전을 동일한 좌표로 이동하는 경우 없애기
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool visited[21][21][21][21];

int min = 11;

void printCoin(vector<pair<int, int>> &coin)
{
    for (auto a : coin)
        cout << a.first << a.second << endl;
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m, 0));
    vector<pair<int, int>> coin;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'o')
                coin.push_back(make_pair(i, j));
        }
    }

    visited[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = true;

    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
    q.push({{coin[0], coin[1]}, 0});
    while (!q.empty())
    {
        int c1_x, c1_y, c2_x, c2_y;
        pair<int, int> x = q.front().first.first;
        pair<int, int> y = q.front().first.second;
        c1_x = q.front().first.first.first;
        c1_y = q.front().first.first.second;
        c2_x = q.front().first.second.first;
        c2_y = q.front().first.second.second;
        int step = q.front().second;
        q.pop();

        if (step >= 10)
        {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx_1, nx_2, ny_1, ny_2;
            nx_1 = c1_x + dx[i];
            ny_1 = c1_y + dy[i];
            nx_2 = c2_x + dx[i];
            ny_2 = c2_y + dy[i];

            if ((nx_1 < 0 || nx_1 == n || ny_1 < 0 || ny_1 == m) && (nx_2 >= 0 && nx_2 < n && ny_2 >= 0 && ny_2 < m))
            {
                cout << step + 1 << endl;
                return 0;
            }
            if ((nx_2 < 0 || nx_2 == n || ny_2 < 0 || ny_2 == m) && (nx_1 >= 0 && nx_1 < n && ny_1 >= 0 && ny_1 < m))
            {
                cout << step + 1 << endl;
                return 0;
            }

            if (nx_1 >= 0 && nx_2 >= 0 && nx_1 < n && nx_2 < n && ny_1 >= 0 && ny_2 >= 0 && ny_1 < m && ny_2 < m)
            {
                pair<int, int> temp1 = x;
                pair<int, int> temp2 = y;
                if (map[nx_1][ny_1] != '#')
                {
                    temp1 = {nx_1, ny_1};
                }
                if (map[nx_2][ny_2] != '#')
                {
                    temp2 = {nx_2, ny_2};
                }
                if (!visited[temp1.first][temp1.second][temp2.first][temp2.second])
                {
                    q.push({{temp1, temp2}, step + 1});
                    visited[temp1.first][temp1.second][temp2.first][temp2.second] = true;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
