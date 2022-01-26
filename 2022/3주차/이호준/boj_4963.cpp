/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
4963 섬의 개수
2022/01/24 이호준
# 아이디어
1. 기존의 BFS에 대각선을 추가하여 풀이한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {-1, 1, 0, 1, -1, 0, 1, -1};

bool visited[51][51];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int x, y;
        cin >> y >> x;
        if (x == 0 && y == 0)
        {
            return 0;
        }
        vector<vector<int>> map(x, vector<int>(y, 0));

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> map[i][j];
            }
        }

        // for (auto a : map) {
        //	for (auto b : a)
        //		cout << b << " ";
        //	cout << endl;
        // }

        int answer = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (map[i][j] && !visited[i][j])
                {
                    visited[i][j] = true;
                    answer++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        int current_x = q.front().first;
                        int current_y = q.front().second;
                        // cout << "visited!!" << current_x << ", " << current_y << endl;
                        q.pop();

                        for (int a = 0; a < 8; a++)
                        {
                            int next_x = current_x + dx[a];
                            int next_y = current_y + dy[a];
                            if (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y)
                            {
                                if (map[next_x][next_y] && !visited[next_x][next_y])
                                {
                                    visited[next_x][next_y] = true;
                                    q.push({next_x, next_y});
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << answer << endl;

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                visited[i][j] = false;
            }
        }
    }

    return 0;
}