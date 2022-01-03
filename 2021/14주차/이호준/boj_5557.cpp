/*******************************************************************
Algorithm Study
Baekjoon OJ DP
5557 1학년
2021/10/13 이호준
# 아이디어
1. 0~20의 숫자만 만들어 질 수 있다.
dfs로 탐색하기에는 너무 큰 경우의 수다
0~20이 현재 만들어 지는 가지수를 저장하면서 dp를 이용한다.
값이 0 ~ 20 까지만 만들어 질 수 있다는 것을 생각해 현재 시점의 상황을 구하고 다음 상황을 생각한다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

long long answer[101][21];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    answer[0][numbers[0]] = 1;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (answer[i - 1][j] != 0)
            {
                if (j + numbers[i] <= 20)
                {
                    answer[i][numbers[i] + j] += answer[i - 1][j];
                }

                if (j - numbers[i] >= 0)
                {
                    answer[i][j - numbers[i]] += answer[i - 1][j];
                }
            }
        }
    }

    cout << answer[n - 2][numbers[n - 1]];

    return 0;
}
