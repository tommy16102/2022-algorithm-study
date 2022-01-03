/*******************************************************************
Algorithm Study
Baekjoon 9주차 다익스트라/이분탐색
1753 최단경로
2021/09/08 이호준
# 아이디어
1. 다익스트라 알고리즘 (Dijkstra’s algorithm)
다익스트라 알고리즘은 개념적으로 알고 있었지만 실제로 구현해서 문제를 풀어본 적은 처음이였다.
맨 처음 접근했을 때 그냥 queue에 넣어서 구현했지만 이는 필요없는 전부의 경우의 수를 체크하는 방식이였다.
모든 경우에 대해서 최단경로인지 확인하기 때문에 O(n^2)을 넘어갔고 메모리초과가 발생했다. 시간에서도 문제가 있을 것 같다.

우선순위 큐를 이용해서 해당 노드까지의 경로 cost를 저장하고 있다면 최선의 순서들 즉 같은 노드라도 cost가 적은 최선의 경우들에
대해서 먼저 확인하고 노드의 cost를 업데이트하기 때문에 실제 queue에 들어가는 노드가 적다는 것을 알 수 있었다.

우선순위 큐를 이용해 다익스트라를 구현하는 기본적인 문제였고 앞으로 이문제를 통해서 다익스트라 문제들을 풀어봐야겠다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[20000];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int start;

    cin >> n >> m;
    cin >> start;

    vector<pair<int, int>> node[20000];

    vector<int> answer(n, 2100000000);
    answer[start - 1] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, weight;

        cin >> u >> v >> weight;

        node[u - 1].push_back({v - 1, weight});
    }

    priority_queue<pair<int, int>> q;

    q.push({0, start - 1});

    while (!q.empty())
    {

        int distance = -q.top().first;
        int current = q.top().second;

        q.pop();

        if (answer[current] < -distance)
            continue;

        for (int i = 0; i < node[current].size(); i++)
        {
            int next = node[current][i].first;
            int next_weight = node[current][i].second;

            if (answer[next] > answer[current] + next_weight)
            {
                answer[next] = answer[current] + next_weight;
                q.push({-answer[next], next});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == start - 1)
            cout << 0 << "\n";
        else
        {
            if (answer[i] != 2100000000)
                cout << answer[i] << "\n";
            else
                cout << "INF\n";
        }
    }

    return 0;
}