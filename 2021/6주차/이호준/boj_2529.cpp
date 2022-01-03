/*******************************************************************
Algorithm Study
Baekjoon 6주차
2529 부등호
2021/08/10 이호준
# 아이디어
1. 문제의 조건에 맞도록 Backtracking을 구현한다.
0 ~ 9까지 다 넣어보면서 되는 경우를 찾는다!
그리고 max와 min을 구한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
bool used[10];
long long min_value = 9999999999;
long long max_value = 0;

void dfs(vector<char> &op, string number, int current);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;

    cin >> k;

    vector<char> op(k, ' ');
    for (int i = 0; i < k; i++)
        cin >> op[i];

    //for (auto a : op)
    //	cout << a << " ";

    for (int i = 0; i < 10; i++)
    {
        used[i] = true;
        dfs(op, to_string(i), 0);
        used[i] = false;
    }

    cout << max_value << endl;
    if (to_string(max_value).size() != to_string(min_value).size())
        cout << "0" + to_string(min_value) << endl;
    else
        cout << min_value << endl;

    return 0;
}

void dfs(vector<char> &op, string number, int current)
{
    if (current == op.size())
    {
        ll check = stoll(number);
        if (check > max_value)
            max_value = check;
        if (check < min_value)
            min_value = check;

        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (used[i] == false)
        {
            ll before;
            before = stoll(number) % 10;
            if (op[current] == '<' && before < i)
            {
                used[i] = true;
                dfs(op, number + to_string(i), current + 1);
            }
            else if (op[current] == '>' && before > i)
            {
                used[i] = true;
                dfs(op, number + to_string(i), current + 1);
            }
            used[i] = false;
        }
    }
}
