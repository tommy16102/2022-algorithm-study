/*******************************************************************
Algorithm Study
Baekjoon OJ DP
14502 연구소
2022/01/17 이호준
# 아이디어
1. 가능한 모든 경우의 수를 탐색한다.
벽을 놓을 수 있는 3가지 경우의 수를 모두 시도하여 체크한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[65][65][65];
bool check_dfs[9][9];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void dfs(int x, int y, vector<vector<int>> &map);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    int virus = 0;
    int wall = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int max = 0;
    /*for (auto a : map) {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }*/
    int size = n * m;
    for (int i = 0; i < size; i++)
    {
        if (map[i / m][i % m] == 0)
            map[i / m][i % m] = 1;
        else
            continue;
        for (int j = i + 1; j < size; j++)
        {
            if (map[j / m][j % m] == 0)
                map[j / m][j % m] = 1;
            else
                continue;
            for (int k = j + 1; k < size; k++)
            {
                if (map[k / m][k % m] == 0)
                    map[k / m][k % m] = 1;
                else
                    continue;
                vector<vector<int>> map2(n, vector<int>(m, 0));
                map2 = map;

                for (int a = 0; a < n; a++)
                {
                    for (int b = 0; b < m; b++)
                    {
                        if (map2[a][b] == 2 && !check_dfs[a][b])
                        {
                            check_dfs[a][b] = true;
                            for (int i = 0; i < 4; i++)
                            {
                                int next_x = a + dx[i];
                                int next_y = b + dy[i];
                                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !check_dfs[next_x][next_y])
                                {
                                    check_dfs[next_x][next_y] = true;
                                    dfs(next_x, next_y, map2);
                                }
                            }
                        }
                    }
                }
                int answer = 0;
                for (auto s : map2)
                    for (auto l : s)
                        if (l == 0)
                            answer++;
                if (max < answer)
                    max = answer;
                for (int s = 0; s < n; s++)
                {
                    for (int l = 0; l < m; l++)
                    {
                        check_dfs[s][l] = false;
                    }
                }
                map[k / m][k % m] = 0;
            }
            map[j / m][j % m] = 0;
        }
        map[i / m][i % m] = 0;
    }

    cout << max;
    return 0;
}

void dfs(int x, int y, vector<vector<int>> &map)
{

    if (map[x][y] != 1)
    {
        map[x][y] = 2;
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < map.size() && next_y >= 0 && next_y < map[0].size())
            {
                if (!check_dfs[next_x][next_y])
                {
                    check_dfs[next_x][next_y] = true;
                    dfs(next_x, next_y, map);
                }
            }
        }
    }
}
