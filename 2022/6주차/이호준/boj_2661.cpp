/*******************************************************************
Algorithm Study
Baekjoon OJ DFS
2661 좋은수열
2022/02/22 이호준
# 아이디어
1. DFS
*******************************************************************/
#include <iostream>
#include <string>

using namespace std;

int n;
string ans = "";
string str = "";

bool dfs(int depth, string num);

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(0, str);
	cout << ans;
	return 0;
}

bool dfs(int depth, string num)
{
	for (int i = 1; i <= num.length() / 2; i++)
	{
		string x = num.substr(num.length() - i, i);
		string y = num.substr(num.length() - i * 2, i);

		if (x == y)return false;
	}
	if (depth == n) {
		ans = num;
		return true;
	}

	for (int i = 1; i <= 3; i++)
	{
		num += (i + '0');
		if (dfs(depth + 1, num)) return true;
		num.pop_back();
	}
	return false;
}