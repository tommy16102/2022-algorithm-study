/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
2606 바이러스
2021/08/18 이호준
# 아이디어
1. bfs로 탐색한다!
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[101];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> map(n + 1);
    int answer = -1;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int i = 0; i < map[a].size(); i++)
        {
            int current = map[a][i];
            if (!visited[current])
            {
                q.push(current);
                visited[current] = true;
            }
        }
    }

    for (auto a : visited)
        if (a == true)
            answer++;

    cout << answer;

    return 0;
}