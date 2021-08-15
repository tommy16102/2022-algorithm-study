/*******************************************************************
Algorithm Study
Baekjoon 6주차
16198 에너지 모으기
2021/08/11 이호준
# 아이디어
1. 사용했던 구슬을 기억하면서 양끝 두개가 남을 때까지 반복한다.
dfs로 맨앞부터 사용하는 것으로 시작해 모든 경우를 탐색하고 max값을 구한다.
이때 사용한 구슬을 기준으로 좌 우에서 사용하지 않은 맨 처음 구슬을 찾아 weight를 계산한다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool check[10];

void dfs(int current, vector<int> &value, int made);

ll max_value = 0;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> value(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    dfs(n, value, 0);

    cout << max_value;

    return 0;
}

void dfs(int current, vector<int> &value, int made)
{
    if (current == 2)
    {
        if (made > max_value)
            max_value = made;
        return;
    }

    for (int i = 1; i < value.size() - 1; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            int weight = 0;
            for (int j = i - 1; j >= 0; j--)
                if (!check[j])
                {
                    weight = value[j];
                    break;
                }
            for (int j = i + 1; j < value.size(); j++)
                if (!check[j])
                {
                    weight *= value[j];
                    break;
                }
            dfs(current - 1, value, made + weight);
            check[i] = false;
        }
    }
}
