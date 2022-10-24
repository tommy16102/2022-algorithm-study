/*******************************************************************
1027 고층 건물
2022/10/24 이호준
# 아이디어
1. Brute Force
*******************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> cnt(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int now = 0; now < n; now++) {
		double maxx = -9999999999;
		for (int i = now + 1; i < n; i++) {
			double level = (double)(arr[i] - arr[now]) / (i - now);
			if (level > maxx) {
				cnt[now]++;
				cnt[i]++;
				maxx = level;
			}
		}
	}
	cout << *max_element(cnt.begin(), cnt.end());
	return 0;
}