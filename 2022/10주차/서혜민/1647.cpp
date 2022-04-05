#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001];

int find(int n) {
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<pair<int, int>, int>> v(M);
	for (int i = 0;i < M;i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;

	sort(v.begin(), v.end(), comp);

	for (int i = 1;i <= N;i++) parent[i] = i;

	int ans = 0;
	int cnt = 1;
	for (int i = 0;i < M;i++) {
		int a = v[i].first.first;
		int b = v[i].first.second;
		int c = v[i].second;
		int d = find(a);
		int e = find(b);
		if (d == e) continue;
		parent[e] = d;
		ans += c;
		cnt++;
		if (cnt == N - 1) {
			cout << ans;
			return 0;
		}
	}
	cout << ans;
}
