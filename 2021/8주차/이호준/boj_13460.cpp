/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
13459 구슬탈출 2
2021/09/03 이호준
# 아이디어
1. 구슬탈출과 동일하다
다만 BFS로 진행했을때 level로 각 case의 수행횟수를 기억하도록 구현했었기 때문에
level이용해 해당 case의 기울임 수행횟수를 출력하도록 출력부분만 수정한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[11][11][11][11];

typedef struct Point
{
    int x;
    int y;
};

typedef struct Marble
{
    Point red;
    Point blue;
};

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;

    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c, ' '));
    Point red;
    Point blue;
    Point finish;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R')
                red = {i, j};
            else if (map[i][j] == 'B')
                blue = {i, j};
            else if (map[i][j] == 'O')
                finish = {i, j};
        }
    }

    Marble marble = {red, blue};

    queue<pair<Marble, int>> q;

    q.push({marble, 0});

    visited[marble.red.x][marble.red.y][marble.blue.x][marble.blue.y] = true;

    while (!q.empty())
    {
        int r_x = q.front().first.red.x;
        int r_y = q.front().first.red.y;
        int b_x = q.front().first.blue.x;
        int b_y = q.front().first.blue.y;
        int level = q.front().second;
        q.pop();

        if (level >= 10)
            break;

        for (int i = 0; i < 4; i++)
        {
            int n_r_x = r_x;
            int n_r_y = r_y;
            int n_b_x = b_x;
            int n_b_y = b_y;

            int r_move = 0;
            int b_move = 0;

            while (map[n_r_x][n_r_y] != '#' && map[n_r_x][n_r_y] != 'O')
            {
                n_r_x += dx[i];
                n_r_y += dy[i];
                r_move++;
            }
            while (map[n_b_x][n_b_y] != '#' && map[n_b_x][n_b_y] != 'O')
            {
                n_b_x += dx[i];
                n_b_y += dy[i];
                b_move++;
            }

            // O을 만나는 케이스 3개 체크
            if (map[n_r_x][n_r_y] == 'O' && map[n_b_x][n_b_y] == 'O')
                continue;
            if (map[n_r_x][n_r_y] == 'O' && map[n_b_x][n_b_y] != 'O')
            {
                cout << level + 1;
                return 0;
            }
            if (map[n_r_x][n_r_y] != 'O' && map[n_b_x][n_b_y] == 'O')
            {
                continue;
            }
            // 새로운 빨간, 파란공의 좌표가 #라 종료된 조건이므로 이동한 방향을 한번 되돌려준다. (벽은 이동 불가능)
            n_r_x -= dx[i];
            n_r_y -= dy[i];
            n_b_x -= dx[i];
            n_b_y -= dy[i];

            // 빨간공과 파란공은 서로 겹칠 수 없다.
            // 더 많이 이동한 공이 이동뱡향에서 하나 덜 가도록 되어야 한다. 덜 이동한 공이 해당 위치를 차지하고 있으므로
            if (n_r_x == n_b_x && n_r_y == n_b_y)
            {
                if (r_move < b_move)
                {
                    n_b_x -= dx[i];
                    n_b_y -= dy[i];
                }
                else
                {
                    n_r_x -= dx[i];
                    n_r_y -= dy[i];
                }
            }
            if (!visited[n_r_x][n_r_y][n_b_x][n_b_y])
            {
                visited[n_r_x][n_r_y][n_b_x][n_b_y] = true;
                q.push({{{n_r_x, n_r_y}, {n_b_x, n_b_y}}, level + 1});
            }
        }
    }
    cout << -1;

    return 0;
}