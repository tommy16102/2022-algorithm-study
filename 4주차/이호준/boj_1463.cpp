/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
1463 1로 만들기
2021/07/27 이호준
# 아이디어
1. 전형적이 DP
i번째 벡터에 i번째까지 도달하느데 걸리는 최소 값을 저장한다. 이전값들을 통해 새로운 경로의 최소값 갱신
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int x;
    cin >> x;
    vector<int> min(x + 1, 21000000);
    min[1] = 0;
    for (int i = 1; i < x; i++)
    {
        if (min[i] + 1 < min[i + 1])
        {
            min[i + 1] = min[i] + 1;
        }
        if (3 * i < x + 1 && min[i] + 1 < min[i * 3])
        {
            min[3 * i] = min[i] + 1;
        }
        if (2 * i < x + 1 && min[i] + 1 < min[i * 2])
        {
            min[2 * i] = min[i] + 1;
        }
    }
    cout << min[x];
    return 0;
}
/*
	10 9 3 1
	16 15 5 4 2 1
	16 8 4 2 1

*/