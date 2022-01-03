/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
1260 DFS와 BFS 
2021/08/04 이호준
# 아이디어
1. 기본적이 DFS와 BFS구현이다. 
DFS와 BFS를 복습할 수 있었다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<bool> &visited, int current, vector<vector<int>> &graph);
void bfs(vector<bool> &visited, int start, vector<vector<int>> &graph);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex, edge, start;
    cin >> vertex >> edge >> start;
    vector<vector<int>> graph(vertex + 1, vector<int>(0, 0));

    for (int i = 0; i < edge; i++)
    {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for (auto &a : graph)
        sort(a.begin(), a.end());
    /*for (int i = 1; i <= vertex; i++)
		sort(graph[i].begin(), graph[i].end());*/
    //for (auto a : graph) {
    //	for (auto b : a)
    //		cout << b << " ";
    //	cout << endl;
    //}
    vector<bool> visited(vertex + 1, false);
    visited[start] = true;
    dfs(visited, start, graph);
    fill(visited.begin(), visited.end(), false);
    cout << "\n";
    bfs(visited, start, graph);
    return 0;
}

void dfs(vector<bool> &visited, int current, vector<vector<int>> &graph)
{
    cout << current << " ";
    for (auto a : graph[current])
    {
        if (visited[a] != true)
        {
            visited[a] = true;
            dfs(visited, a, graph);
        }
    }
}

void bfs(vector<bool> &visited, int start, vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (auto a : graph[current])
        {
            if (visited[a] != true)
            {
                visited[a] = true;
                q.push(a);
            }
        }
    }
}
/*
4 5 1
1 2
1 3
1 4
2 4
3 4
*/