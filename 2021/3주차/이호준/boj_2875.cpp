/*******************************************************************
Algorithm Study
Baekjoon 알고리즘 중급 1 / 3 그리디알고리즘(연습)
2875 대회 or 인턴
2021/07/22 이호준
# 아이디어
1. 여자 팀원이 2명필요하므로 여자팀원 개수를 기준으로 가능한 최대 팀개수 구하기
2. 현재 팀구성으로 인턴 K명을 충족할 수 있는지 확인
3. 충족할 수 없다면 팀하나를 해체하고 인턴 채용
*******************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N, M, K;
    int team = 0;
    cin >> N >> M >> K;
    // 팀을 최대한 많이
    // 팀개수는 2 : 1, 여자수에 더 큰 비중이 있다.
    int max = N / 2;
    while (M < max)
    {
        max--;
    }
    team = max;
    if (K - (M - max) - (N - 2 * team) > 0)
    {
        // need to reduce team size
        K = K - (M - max) - (N - 2 * team);
        while (K > 0)
        {
            team--;
            K -= 3;
        }
    }
    if (team < 0)
        team = 0;
    cout << team;
}