/*******************************************************************
Algorithm Study
Baekjoon 6주차
5014 스타트링크
2021/08/12 이호준
# 아이디어
1. 문제가 요구하는 대로 bfs로 탐색한다. (최솟값이므로)
이때 used 배열을 통해 이미 방문한 층은 방문하지 않는다. 
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool used[1000001];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int answer = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    used[s] = true;
    //예외
    if (s < g && u == 0)
    {
        cout << "use the stairs" << endl;
        return 0;
    }
    if (s > g && d == 0)
    {
        cout << "use the stairs" << endl;
        return 0;
    }

    while (!q.empty())
    {
        int current_floar = q.front().first;
        int push_count = q.front().second;
        q.pop();
        if (current_floar == g)
        {
            cout << push_count << endl;
            return 0;
        }

        if (current_floar + u <= f)
        {
            if (!used[current_floar + u])
            {
                q.push(make_pair(current_floar + u, push_count + 1));
                used[current_floar + u] = true;
            }
        }
        if (current_floar - d > 0)
        {
            if (!used[current_floar - d])
            {
                q.push(make_pair(current_floar - d, push_count + 1));
                used[current_floar - d] = true;
            }
        }
    }
    cout << "use the stairs" << endl;

    return 0;
}