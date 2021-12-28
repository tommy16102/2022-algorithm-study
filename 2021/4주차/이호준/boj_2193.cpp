/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
2193 이친수 
2021/07/30 이호준
# 아이디어
1. 문제가 요구하는데로 0일때와 1일때 나눠서 풀었다.
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    // N = 1 -> 1, N = 2 -> 1

    vector<vector<ll>> binary(N + 1, vector<ll>(2, 0));
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    binary[1][1] = binary[2][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        binary[i][0] = binary[i - 1][0] + binary[i - 1][1];
        binary[i][1] = binary[i - 1][0];
    }

    cout << binary[N][0] + binary[N][1];

    return 0;
}