/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
13913 숨바꼭질4
2021/09/03 이호준
# 아이디어
1. path를 저장하기 위해서 parent 배열을 통해 linked list처럼 역순으로 연결되도록 연결한다.
*******************************************************************/
#include <iostream>
#include <queue>
using namespace std;

bool visited[200001];
int parent[100001];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;
    int answer = -1;
    int answer_count = 0;
    queue<pair<int, int>> q;
    vector<int> path;
    visited[n] = true;
    q.push({n, 0});
    while (!q.empty())
    {
        int value = q.front().first;
        int count_value = q.front().second;
        q.pop();

        if (value == k)
        {
            cout << count_value << endl;
            while (value != n)
            {
                path.push_back(value);
                value = parent[value];
            }
            path.push_back(value);
            break;
        }

        if (!visited[value + 1] && value + 1 < 100001)
        {
            q.push({value + 1, count_value + 1});
            parent[value + 1] = value;
            visited[value + 1] = true;
        }
        if (!visited[value - 1] && value - 1 >= 0)
        {
            q.push({value - 1, count_value + 1});
            parent[value - 1] = value;
            visited[value - 1] = true;
        }
        if (!visited[value * 2] && value * 2 < 100001)
        {
            q.push({value * 2, count_value + 1});
            parent[value * 2] = value;
            visited[value * 2] = true;
        }
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    return 0;
}

/*
 곱하기 2와 플러스 1 마이너스 1
*/