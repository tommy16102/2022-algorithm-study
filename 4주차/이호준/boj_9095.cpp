/*******************************************************************
Algorithm Study
Baekjoon SW 역량테스트 준비 기초
9095 1, 2, 3 더하기 
2021/07/28 이호준
# 아이디어
1. 결국 이문제도 동일했다.
예외가 되는 케이스 1, 2, 3 케이스까지는 별도로 설정해주고
4부터 맨뒤에 1을 더했다고 가정했을 때, 2를 더했다고 가정했을 때, 3을 더했다고 가정했을 때로 나눈다면
f(n) = f(n-1) + f(n-2) + f(n-3)으로 표현할 수 있다.
4 = 3 + 1, 2 + 2, 1 + 3
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
    vector<int> min(max + 1, 0);

    min[1] = 1;
    min[2] = 2;
    min[3] = 4;
    for (int i = 4; i <= max; i++)
    {
        min[i] = min[i - 3] + min[i - 2] + min[i - 1];
    }
    for (auto &a : input)
    {
        cout << min[a] << "\n";
    }
    return 0;
}

/*
	1+1
	2
	
	1+1+1
	1+2
	2+1
	3


*/