/*******************************************************************
Algorithm Study
Baekjoon 8주차 스택/BFS/DFS
2493 탑
2021/09/01 이호준
# 아이디어
1. stack안에 나보다 큰값이 나타날때까지 확인하고 push한다.
stack에 넣을때 pair로 현재 value와 position정보를 넣는다.

나보다 작은 탑은 신경쓸필요가 없기에 가능하다.
큰값이 있으면 그것을 보기때문에 문제없다.
*******************************************************************/
#include <stack>
#include <iostream>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    int x;
    cin >> x;
    stack<pair<int, int>> s;
    s.push({x, 0});
    cout << 0 << " ";
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x > s.top().first)
        {
            s.pop();
            while (!s.empty())
            {
                if (x < s.top().first)
                {
                    cout << s.top().second + 1 << " ";
                    s.push({x, i});
                    break;
                }
                else if (x == s.top().first)
                {
                    cout << s.top().second + 1 << " ";
                    s.top().second = i;
                    break;
                }
                s.pop();
            }
            if (s.empty())
            {
                s.push({x, i});
                cout << 0 << " ";
            }
        }
        else if (x == s.top().first)
        {
            cout << s.top().second + 1 << " ";
            s.top().second = i;
        }
        else
        {
            cout << s.top().second + 1 << " ";
            s.push({x, i});
        }
    }

    return 0;
}