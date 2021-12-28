/*******************************************************************
Algorithm Study
Baekjoon 6주차
14225 부분 수열의 합
2021/08/11 이호준
# 아이디어
1. dfs로 모든 경우를 탐색하는데 
사용되었을 때와 사용안되었을 때로 나눠서 탐색하고
합이 생성되었는지 확인하는 bool 배열을 만든다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool made[2000000];

void dfs(int current, int sum, vector<int> &value);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> value(n, 0);
    for (int i = 0; i < n; i++)
        cin >> value[i];

    dfs(0, 0, value);

    for (int i = 0; i < 2000000; i++)
        if (!made[i])
        {
            cout << i;
            break;
        }

    return 0;
}

void dfs(int current, int sum, vector<int> &value)
{
    if (current == value.size())
    {
        if (!made[sum])
            made[sum] = true;
        return;
    }

    dfs(current + 1, sum + value[current], value);
    dfs(current + 1, sum, value);
}
