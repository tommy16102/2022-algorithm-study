/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
11286 절대값 힙
2021/09/01 이호준
# 아이디어
1. 음수를 max힙에 넣고 양수를 min힙에 넣어서
절대값이 더 작은 값을 top에서 찾아서 출력하도록 구현한다.
*******************************************************************/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isNegative(int x) { return x < 0; }

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<>> min;

    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (isNegative(x))
            max.push(x);
        else
        {
            if (x == 0)
            {
                if (min.empty() && max.empty())
                {
                    cout << 0 << "\n";
                }
                else if (min.empty() && !max.empty())
                {
                    cout << max.top() << "\n";
                    max.pop();
                }
                else if (max.empty() && !min.empty())
                {
                    cout << min.top() << "\n";
                    min.pop();
                }
                else if (max.top() * (-1) > min.top())
                {
                    cout << min.top() << "\n";
                    min.pop();
                }
                else if (max.top() * (-1) < min.top())
                {
                    cout << max.top() << "\n";
                    max.pop();
                }
                else
                {
                    cout << max.top() << "\n";
                    max.pop();
                }
            }
            else
            {
                min.push(x);
            }
        }
    }

    return 0;
}
