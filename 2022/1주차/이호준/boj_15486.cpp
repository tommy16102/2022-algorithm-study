/*******************************************************************
Algorithm Study
Baekjoon OJ DP
15486 퇴사 2
2022/01/04 이호준
# 아이디어
1. dp로 문제해결. 항상 최선의 선택을 하도록.
추가적으로 일을하지 않는 경우도 고려
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
        if (i + input[i][0] < day + 1 && answer[i + input[i][0]] < answer[i] + input[i][1])
        {
            answer[i + input[i][0]] = answer[i] + input[i][1];
        }

        if (i + 1 < day + 1 && answer[i] > answer[i + 1])
        {
            answer[i + 1] = answer[i];
        }
    }

    cout << answer[day];

    return 0;
}