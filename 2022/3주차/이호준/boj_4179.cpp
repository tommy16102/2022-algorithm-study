/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
4179 불!
2022/01/26 이호준
# 아이디어
1. 불BFS와 사람 BFS를 동시에 진행한다.
level을 두고 새로운 level의 bfs를 진행하기 전에 불을 먼저 진행시킨다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool visited[1001][1001];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;

    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c, ' '));

    pair<int, int> start;
    vector<pair<int, int>> fire;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char temp;
            cin >> temp;
            map[i][j] = temp;
            if (temp == 'J')
                start = {i, j};
            else if (temp == 'F')
                fire.push_back({i, j});
        }
    }

    if (start.first == 0 || start.first == r - 1 || start.second == 0 || start.second == c - 1)
    {
        cout << 1 << endl;
        return 0;
    }

    queue<pair<pair<int, int>, int>> q;
    queue<pair<pair<int, int>, int>> fires;
    map[start.first][start.second] = '.';
    // 처음 위치에서 상하좌우
    for (int i = 0; i < 4; i++)
    {
        int next_x = start.first + dx[i];
        int next_y = start.second + dy[i];
        visited[start.first][start.second] = true;

        if (next_x >= 0 && next_x < r && next_y < c && next_y >= 0)
        {
            // 경계선 (탈출)
            if (next_x == 0 || next_x == r - 1 || next_y == 0 || next_y == c - 1)
            {
                bool flag = true;
                for (int b = 0; b < 4; b++)
                {
                    int next_fire_x = next_x + dx[b];
                    int next_fire_y = next_y + dy[b];
                    if (next_fire_x < r && next_fire_x >= 0 && next_fire_y < c && next_fire_y >= 0)
                    {
                        if (map[next_fire_x][next_fire_y] == 'F')
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag && map[next_x][next_y] == '.')
                {
                    cout << 2 << "1" << endl;
                    return 0;
                }
            }
            // 경계선아니면 BFS 시작
            if (map[next_x][next_y] != '#' && map[next_x][next_y] != 'F')
            {
                q.push({{next_x, next_y}, 1});
                visited[next_x][next_y] = true;
            }
        }
    }
    vector<vector<char>> map2(map);

    for (int j = 0; j < fire.size(); j++)
        fires.push({{fire[j].first, fire[j].second}, 0});

    while (!q.empty())
    {

        int go_x = q.front().first.first;
        int go_y = q.front().first.second;
        int current_step = q.front().second;
        q.pop();
        // cout << "check " << go_x << " " << go_y << " step " << current_step << endl;
        /*for (auto a : map2) {
            for (auto b : a)
                cout << b << " ";
            cout << endl;
        }*/

        // 불 확산 로직
        while (!fires.empty() && fires.front().second < current_step)
        {
            int fire_x = fires.front().first.first;
            int fire_y = fires.front().first.second;
            int next_fire = fires.front().second;
            fires.pop();
            for (int a = 0; a < 4; a++)
            {
                int next_fire_x = fire_x + dx[a];
                int next_fire_y = fire_y + dy[a];

                if (next_fire_x >= 0 && next_fire_x < r && next_fire_y >= 0 && next_fire_y < c)
                {
                    if (map2[next_fire_x][next_fire_y] != '#' && map2[next_fire_x][next_fire_y] != 'F')
                    {
                        map2[next_fire_x][next_fire_y] = 'F';
                        /*int temp = current_step;
                        if (current_step == 1) {
                            temp = 1;
                        }*/
                        // cout << "fires " << next_fire_x << " " << next_fire_y << endl;
                        fires.push({{next_fire_x, next_fire_y}, next_fire + 1});
                    }
                }
            }
        }

        /*for (auto a : map2) {
            for (auto b : a)
                cout << b << " ";
            cout << endl;
        }*/

        if (go_x == 0 || go_x == r - 1 || go_y == 0 || go_y == c - 1)
        {
            bool flag = true;
            for (int b = 0; b < 4; b++)
            {
                int next_fire_x = go_x + dx[b];
                int next_fire_y = go_y + dy[b];
                if (next_fire_x < r && next_fire_x >= 0 && next_fire_y < c && next_fire_y >= 0)
                {
                    if (map2[next_fire_x][next_fire_y] == 'F')
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && map2[go_x][go_y] == '.')
            {
                cout << current_step + 1 << endl;
                return 0;
            }
        }

        // 이동
        for (int a = 0; a < 4; a++)
        {
            int next_go_x = go_x + dx[a];
            int next_go_y = go_y + dy[a];
            if (next_go_x >= 0 && next_go_x < r && next_go_y >= 0 && next_go_y < c)
            {
                if (!visited[next_go_x][next_go_y] && map2[next_go_x][next_go_y] == '.')
                {
                    if (next_go_x == 0 || next_go_x == r - 1 || next_go_y == 0 || next_go_y == c - 1)
                    {
                        // 지금 탈출 위치의 상하좌우에 F가 있는 경우는 불에 의해서 죽는 경우로 해당 경우를 checking하기 위한 로직
                        bool flag = true;
                        for (int b = 0; b < 4; b++)
                        {
                            int next_fire_x = next_go_x + dx[b];
                            int next_fire_y = next_go_y + dy[b];
                            if (next_fire_x < r && next_fire_x >= 0 && next_fire_y < c && next_fire_y >= 0)
                            {
                                if (map2[next_fire_x][next_fire_y] == 'F')
                                {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if (flag)
                        {
                            // cout << "solution" << next_go_x << " " << next_go_y << endl;
                            /*for (auto a : map2) {
                                for (auto b : a)
                                    cout << b << " ";
                                cout << endl;
                            }*/
                            cout << current_step + 2 << endl;
                            return 0;
                        }
                    }
                    // cout << next_go_x << " " << next_go_y << " connt " << current_step + 1 << endl;
                    visited[next_go_x][next_go_y] = true;
                    q.push({{next_go_x, next_go_y}, current_step + 1});
                }
            }
        }
    }
    for (int a = 0; a < r; a++)
    {
        for (int b = 0; b < c; b++)
        {
            visited[a][b] = false;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
