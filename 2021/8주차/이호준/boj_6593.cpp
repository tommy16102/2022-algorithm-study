/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
6593 상범빌딩
2021/09/03 이호준
# 아이디어
1. 3차원 BFS 원리는 동일했다 3차원일뿐. Point struct를 만들어서 처리했다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[31][31][31];

void printMap(vector<vector<vector<char>>> map)
{
    for (auto a : map)
    {
        for (auto b : a)
        {
            for (auto c : b)
                cout << c << " ";
            cout << endl;
        }
        cout << endl;
    }
}

typedef struct Point
{
    int x;
    int y;
    int z;
};

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {

        int l, r, c;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
        {
            break;
        }
        Point start;
        Point end;

        vector<vector<vector<char>>> map(l, vector<vector<char>>(r, vector<char>(c, ' ')));

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S')
                        start = {j, k, i};
                    if (map[i][j][k] == 'E')
                        end = {j, k, i};
                }
            }
        }

        queue<pair<Point, int>> q;

        q.push({start, 0});
        visited[start.z][start.x][start.y] = true;
        bool find = false;
        int finish;

        while (!q.empty())
        {
            int x = q.front().first.x;
            int y = q.front().first.y;
            int z = q.front().first.z;
            int level = q.front().second;
            q.pop();

            if (x == end.x && y == end.y && z == end.z)
            {
                find = true;
                finish = level;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < r && nx >= 0 && ny >= 0 && ny < c)
                {
                    if (!visited[z][nx][ny] && map[z][nx][ny] != '#')
                    {
                        q.push({{nx, ny, z}, level + 1});
                        visited[z][nx][ny] = true;
                    }
                }
                if (z + 1 < l)
                {
                    if (!visited[z + 1][x][y] && map[z + 1][x][y] != '#')
                    {
                        q.push({{x, y, z + 1}, level + 1});
                        visited[z + 1][x][y] = true;
                    }
                }
                if (z - 1 >= 0)
                {
                    if (!visited[z - 1][x][y] && map[z - 1][x][y] != '#')
                    {
                        q.push({{x, y, z - 1}, level + 1});
                        visited[z - 1][x][y] = true;
                    }
                }
            }
        }

        if (find)
            cout << "Escaped in " << finish << " minute(s).\n";
        else
            cout << "Trapped!\n";

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    visited[i][j][k] = false;
                }
            }
        }
    }

    return 0;
}
