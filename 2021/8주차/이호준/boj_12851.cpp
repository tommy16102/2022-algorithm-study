/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
12851 숨바꼭질2
2021/09/01 이호준
# 아이디어
1. bfs를 통해 구현한다.
같은 value가 되기 위한 case가 pop되기전까지는 같은 value로 오는 case가 다른경우를 모두 check해야한다.
해당 value가 pop된 다음에는 해당 value가 되는 케이스가 있더라도 value에 오는 경우가 더 늦게 오는 path로 문제의 고려대상이 아니다.
그러므로 pop을 진행하고 visited를 true로 하는 방식으로 bfs를 구현한다.
*******************************************************************/
#include <iostream>
#include <queue>
using namespace std;

bool visited[200001];

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
    visited[n] = true;
    q.push({n, 0});
    while (!q.empty())
    {
        int value = q.front().first;
        int count_value = q.front().second;
        q.pop();
        visited[value] = true;
        if (answer != -1 && count_value > answer)
        {
            cout << answer_count << "\n";
            return 0;
        }

        if (value == k)
        {
            if (answer == -1)
            {
                answer = count_value;
                cout << count_value << "\n";
            }
            if (count_value == answer)
            {
                answer_count++;
            }
        }

        if (!visited[value * 2] && value * 2 < 100001)
        {
            q.push({value * 2, count_value + 1});
        }

        if (!visited[value + 1] && value + 1 < 100001)
        {
            q.push({value + 1, count_value + 1});
        }
        if (!visited[value - 1] && value - 1 >= 0)
        {
            q.push({value - 1, count_value + 1});
        }
    }
    cout << answer_count << "\n";
    return 0;
}

/*
 곱하기 2와 플러스 1 마이너스 1
*/