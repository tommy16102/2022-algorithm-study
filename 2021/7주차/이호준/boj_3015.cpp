/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 자료구조2
3015 오아시스
2021/08/21 이호준

구글의 답을 참조하였다. 
O(n^2)으로는 문제의 제한시간을 맞출 수 없기에 스택에 넣으면서 O(n)에 처리할 수 있도록 해야한다.
스택에서 pop을 해야하는 문제의 제한조건을 구현하고 이때 pair를 이용해 같은값을 처리하는 풀이였다.
스택의 사용법과 문제해결에 대해서 배울 수 있었다.
*******************************************************************/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

stack<pair<int, int>> sta;

int main()
{
    int N;
    long long ans = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        pair<int, int> p = {a, 1};
        while (!sta.empty())
        {
            if (sta.top().first <= p.first)
            {
                ans += sta.top().second;
                if (sta.top().first == p.first)
                {
                    p.second += sta.top().second;
                }
                sta.pop();
            }
            else
            {
                ans++;
                break;
            }
        }
        sta.push(p);
    }
    cout << ans << endl;
}