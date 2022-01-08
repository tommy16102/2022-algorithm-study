/*******************************************************************
Algorithm Study
Baekjoon OJ DP
11724 연결 요소의 개수
2022/01/08 이호준
# 아이디어
1. dfs를 이용해서 갈수있는데 까지 탐색한다. 또한 방문한 node에 대해서 visited여부를 기억하여 연결요수의 개수를 구한다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];

void dfs(int start, vector<vector<bool>> &map);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex, edge;

    cin >> vertex >> edge;

    vector<vector<bool>> map(vertex + 1, vector<bool>(vertex + 1, 0));

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u][v] = true;
        map[v][u] = true;
    }

    int answer = 0;

    for (int i = 1; i <= vertex; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i, map);
            answer += 1;
        }
    }

    cout << answer;

    return 0;
}

void dfs(int start, vector<vector<bool>> &map)
{
    for (int i = 1; i <= map.size() - 1; i++)
    {
        if (!visited[i])
        {
            if (map[start][i])
            {
                visited[i] = true;
                dfs(i, map);
            }
        }
    }
}