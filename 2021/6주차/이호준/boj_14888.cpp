/*******************************************************************
Algorithm Study
Baekjoon 6주차
14888 연산자 끼워넣기
2021/08/12 이호준
# 아이디어
1. dfs와 backtracking으로 구현한다.
왜 속도차이가 그렇게 많이 나는지 모르겠다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int current, int made, vector<int> &values, vector<int> &operators);

int max_value = -1000000000;
int min_value = 1000000000;

bool used[12];

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> values(n, 0);

    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<int> operators;
    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
            operators.push_back(i);
        // 0 == + , 1 == - , 2 == * , 3 == %
    }
    dfs(1, values[0], values, operators);

    cout << max_value << endl;
    cout << min_value << endl;

    return 0;
}

void dfs(int current, int made, vector<int> &values, vector<int> &operators)
{
    if (current == operators.size() + 1)
    {
        if (made > max_value)
            max_value = made;
        if (made < min_value)
            min_value = made;
        return;
    }

    for (int i = 0; i < operators.size(); i++)
    {
        // 사용되지 않은 연산자 사용
        if (!used[i])
        {
            used[i] = true;
            int temp = made;
            switch (operators[i])
            {
            case 0:
                temp += values[current];
                break;
            case 1:
                temp -= values[current];
                break;
            case 2:
                temp *= values[current];
                break;
            case 3:
                temp /= values[current];
                break;
            }
            dfs(current + 1, temp, values, operators);
            used[i] = false;
        }
    }
}
