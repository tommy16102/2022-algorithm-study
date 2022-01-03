/*******************************************************************
Algorithm Study
Baekjoon OJ DP
14501 퇴사
2021/10/06 이호준
# 아이디어
1. DP 이용

dp 문제로 해당 날짜의 최대 값을 구하도록 구현한다.
해당 날짜의 최대가 되는 방법은 2가지이다.
1. 어떤날의 작업이 끝난 날짜인 경우.
2. 이전날의 작업이 더 크고 오늘은 쉬는 날인 경우.

두 경우 중 max를 구해 최대값을 가지도록 구현한다.
*******************************************************************/
#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int day;

    cin >> day;

    vector<vector<int>> input(day + 1, vector<int>(2));

    for (int i = 0; i < day; i++)
    {
        cin >> input[i][0] >> input[i][1];
    }

    vector<int> answer(day + 1, 0);

    for (int i = 0; i < day + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == j + input[j][0])
            {
                if (answer[i] < answer[j] + input[j][1])
                {
                    answer[i] = answer[j] + input[j][1];
                }
            }
            else if (answer[j] > answer[i])
            {
                answer[i] = answer[j];
            }
        }
    }

    cout << answer[day];

    return 0;
}