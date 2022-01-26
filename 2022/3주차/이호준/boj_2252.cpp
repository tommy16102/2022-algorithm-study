/*******************************************************************
Algorithm Study
Baekjoon OJ 위상정렬
2252 줄 세우기
2022/01/26 이호준
# 아이디어
1. 위상정렬에 대해서 배웠다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> graph[32001];
int ind[32001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        ind[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int nx : graph[x])
        {
            ind[nx]--;
            if (ind[nx] == 0)
                q.push(nx);
        }
    }
    cout << '\n';
    return 0;
}