/*******************************************************************
Algorithm Study
Baekjoon OJ DP
13549 숨바꼭질 3
2022/01/19 이호준
# 아이디어
1. BFS로 구현하였다. *2를 우선 처리해야한다.
*******************************************************************/
#include <iostream>
#include <queue>
#include <cmath>

bool visited[100001];
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int current, target;

    cin >> current >> target;

    queue<pair<int, int>> q;
    q.push({current, 0});
    visited[current] = true;
    while (!q.empty())
    {
        int check = q.front().first;
        int visited_count = q.front().second;
        q.pop();

        if (check == target)
        {
            cout << visited_count;
            return 0;
        }

        if (check * 2 <= 100000 && !visited[check * 2])
        {
            q.push({check * 2, visited_count});
            visited[check * 2] = true;
            // cout << next << " " << q.size() << endl;
        }

        if (check == 0)
        {
            if (!visited[1])
            {
                q.push({1, visited_count + 1});
                visited[1] = true;
                continue;
            }
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                int next = check + pow(-1, i + 1);
                if (!visited[next] && next <= 100001)
                {
                    q.push({next, visited_count + 1});
                    visited[next] = true;
                    // cout << next << " " << q.size() << endl;
                }
            }
        }
    }

    return 0;
}