/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
11279 최대 힙
2021/08/18 이호준
# 아이디어
1. priority queue를 사용하면 된다!.
*******************************************************************/
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            if (q.empty())
                cout << 0 << "\n";
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(command);
        }
    }

    return 0;
}