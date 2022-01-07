/*******************************************************************
Algorithm Study
Baekjoon OJ DP
7562 나이트의 이동
2022/01/04 이호준
# 아이디어
1. 최소 이동거리를 구하는 문제이다. -> BFS를 이용하여 나이트가 갈 수 있는 최단횟수를 구하도록 구현
나이트는 상하좌우 즉, 4가지 방향에 대해서 해당방향 2번 이동 대각선 이동 (해당 방향*2 + 90도 각도로 이동의 원리)로 이동한다.
이를 구현하고 최초로 end 지점에 가게 되면 종료하게 된다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool map[301][301];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case_num = 0;

    cin >> test_case_num;

    for (int i = 0; i < test_case_num; i++)
    {
        int size = 0;
        cin >> size;
        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        queue<pair<pair<int, int>, int>> q;
        q.push({start, 0});
        map[start.first][start.second] = true;
        while (!q.empty())
        {
            int current_x = q.front().first.first;
            int current_y = q.front().first.second;
            int current_count = q.front().second;
            q.pop();

            if (current_x == end.first && current_y == end.second)
            {
                cout << current_count << endl;
                for (auto &a : map)
                {
                    for (auto &b : a)
                        b = false;
                }
                break;
            }

            for (int j = 0; j < 4; j++)
            {
                for (int a = 0; a < 2; a++)
                {
                    int next_x = current_x + 2 * dx[j];
                    int next_y = current_y + 2 * dy[j];
                    if (dx[j])
                    {
                        a == 0 ? next_y += 1 : next_y += -1;
                    }
                    if (dy[j])
                    {
                        a == 0 ? next_x += 1 : next_x += -1;
                    }
                    if (next_x >= 0 && next_x < size && next_y >= 0 && next_y < size)
                    {
                        // cout << next_x << "  " << next_y << endl;
                        if (!map[next_x][next_y])
                        {
                            q.push({{next_x, next_y}, current_count + 1});
                            map[next_x][next_y] = true;
                        }
                    }
                }
            }
        }
    }
    return 0;
}