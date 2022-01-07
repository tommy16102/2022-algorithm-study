/*******************************************************************
Algorithm Study
Baekjoon OJ DP
2293 동전1
2022/01/05 이호준
# 아이디어
1. DP 문제
동전을 조합하여 해당 숫자를 만드는 문제.
중복되면 안됨 -> 조합 선택하는 문제
동전마다 해당 동전을 사용하는 dp를 이용하여 중복되지 않도록 구현

※프로그래머스 https://programmers.co.kr/learn/courses/30/lessons/12907 (거스름 돈과 비슷)
*******************************************************************/
#include <iostream>

using namespace std;

int dp[10001];
int number[101];

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, target;

	cin >> n >> target;

	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = number[i]; j <= target; j++)
		{
			dp[j] += dp[j - number[i]];
		}
	}
	cout << dp[target] << endl;
	return 0;
}