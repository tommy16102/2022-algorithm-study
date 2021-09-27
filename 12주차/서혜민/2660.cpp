#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/* 2021.09.27 플로이드 와샬(삼중 포문)을 이용.

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int friends[51][51];

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			friends[i][j] = 10000000;
		}
	}
	
	while (1) {
		int f1, f2;
		cin >> f1 >> f2;
		if (f1 == -1 && f2 == -1) break;
		friends[f1][f2] = 1;
		friends[f2][f1] = 1;
	}

	for (int t = 1;t <= n;t++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				friends[i][j] = min(friends[i][j], friends[i][t] + friends[t][j]);

	vector<pair<int, int>> v;
	for (int i = 1;i <= n;i++) {
		int max = 0;
		for (int j = 1;j <= n;j++) {
			if (i == j) continue;
			if (friends[i][j] > max) {
				max = friends[i][j];
			}
		}
		v.push_back({ max,i });
	}

	sort(v.begin(), v.end());
	
	int min = v[0].first;
	
	vector<int> ans;
	for (auto& i : v) {
		if (i.first== min) {
			ans.push_back(i.second);
		}
	}
	
	cout << min << ' ' << ans.size() << endl;
	for (auto& i : ans)cout << i << ' ';
	cout << endl;
}
