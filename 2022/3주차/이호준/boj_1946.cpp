/*******************************************************************
Algorithm Study
Baekjoon OJ
1946 신입사원
2022/01/25 이호준
# 아이디어
1등은 우선 합격
2등은 1등의 2차보다 높아야함..
3등은 1, 2 차중 보다 높은 사람이 있어야함...

=> 1등부터 2차 점수의 최소점을 파악하여
해당 점수보다 높으면 바로 탈락

*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> input(n, {0, 0});
        for (int j = 0; j < n; j++)
        {
            cin >> input[j].first >> input[j].second;
        }
        sort(input.begin(), input.end());
        int count = 0;
        int min_value = input[0].second;
        for (int a = 1; a < n; a++)
        {
            if (min_value > input[a].second)
            {
                min_value = input[a].second;
            }
            else
            {
                count++;
            }
        }
        cout << n - count << endl;
    }

    return 0;
}