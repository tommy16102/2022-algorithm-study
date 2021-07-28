/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
15988 1, 2, 3 더하기3
2021/07/28 이호준
# 아이디어
1. 그냥 %만 나눠주면 될줄 알았으나 오버플로우가 난다는 사실을 알게되었다.
int가 21억인데 %가 10억이다. 이떄 함수식에서 +이 3개이므로 최대 10억 * 3이 되어 30억이 되어 오버플로우가 발생할 수 있다는 것을 확인하였다.
그래서 unsigned int로 변경하니 문제없이 돌아갔다.

※ 값의 범위에 대해서 다시 생각해 볼 수 있었다.
생각보다 덧셈의 힘이 컸다.... index 80정도만가도 억이 되는 숫자였다..
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int max = *max_element(input.begin(), input.end());
    if (max <= 3)
    {
        for (auto &a : input)
        {
            cout << (a == 1 ? 1 : a == 2 ? 2
                                         : 4)
                 << "\n";
            return 0;
        }
    }
    vector<unsigned int> min(max + 1, 0);

    min[1] = 1;
    min[2] = 2;
    min[3] = 4;
    for (int i = 4; i <= max; i++)
    {
        min[i] = min[i - 3] + min[i - 2] + min[i - 1];
        min[i] %= 1000000009;
    }
    for (auto &a : input)
    {
        cout << min[a] << "\n";
    }
    return 0;
}