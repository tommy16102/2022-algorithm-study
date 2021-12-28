/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
16194 카드 구매하기2
2021/07/28 이호준
# 아이디어
1. 카드 구매하기 1과 동일하다.
다만 부호가 반대이다.
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> price(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> price[i];
    }
    vector<int> max(N + 1, 210000000);
    max[0] = 0; // 0 + price 하기 위해서
    max[1] = price[1];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (max[j] + price[i + 1 - j] < max[i + 1])
            {
                max[i + 1] = max[j] + price[i + 1 - j];
            }
        }
    }
    cout << max[N];
    return 0;
}
