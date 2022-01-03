/*******************************************************************
Algorithm Study
Baekjoon 6주차
6603 로또
2021/08/10 이호준
# 아이디어
1. 조합을 이용해 구현한다!
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

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> number(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> number[i];
        }

        vector<bool> combination(n, false);
        for (int i = 0; i < 6; i++)
            combination[i] = true;

        do
        {

            for (int i = 0; i < n; i++)
            {
                if (combination[i])
                {
                    cout << number[i] << " ";
                }
            }
            cout << endl;

        } while (prev_permutation(combination.begin(), combination.end()));

        cout << endl;
    }

    return 0;
}