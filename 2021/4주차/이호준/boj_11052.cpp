/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
11052 카드구매하기
2021/07/28 이호준
# 아이디어
1. N이 10이라할때 1~10까지 가면서 각 max를 구하면 되지않을까?
이떄 10이 될 수 있는 경우를 생각해보면 0+10, 1+9, 2+8, 3+7, 4+6, 5+5다..
결국 각 경우들이 모두 max이므로 max들중 max를 구햐면 되지않을까?
모든 case를 덮을 수 있을 것 같다.
만약 1원 짜리가 전부 계속 max였다면 9까지 작성되면서 max가 1원짜리들로 작성되었을 것이므로..
결국 max들을 만들어가면 max를 만들 수 있다.
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
    vector<int> max(N + 1, 0);
    max[1] = price[1];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (max[j] + price[i + 1 - j] > max[i + 1])
            {
                max[i + 1] = max[j] + price[i + 1 - j];
            }
        }
    }
    cout << max[N];
    return 0;
}
/*
 1 ~ 10이라치면 10까지 가는데
 각 합의 max를 만들면서 진행해야한다!
 1 + 9 가 max라면 결국 9도 max인데 이 max가 1로부터 만들어졌다... 이런전개..
*/