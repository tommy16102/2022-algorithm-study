/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
1297 최소 힙
2021/08/18 이호준
# 아이디어
1. 최소 힙을 사용하면된다.
greater<int>를 이용해 작은 값부터 출력하도록 한다.
*******************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> q;

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