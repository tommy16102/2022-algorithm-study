/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
11727 2*n 타일링2 
2021/07/28 이호준
# 아이디어
1. 11726과 같은 문제에 2*2 타일이 추가되었다.
결국 2*2타일은 2*1타일과 같은 경우의 수라고 생각할 수 있다.
그래서 뒤에 2*2타일을 붙였을 때, 2*1 타일을 붙였을 때, 1*2 타일을 붙였을 때로 나누면
f(n) = f(n-2) + f(n-2) + f(n-1) 로 정리할 수 있다.
*******************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> min(n + 1, 210000000);
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    min[1] = 1;
    min[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        min[i] = 2 * min[i - 2] + min[i - 1];
        min[i] %= 10007;
    }
    cout << min[n];
    return 0;
}

/*
0005
5 3 4
6 5 4
*/