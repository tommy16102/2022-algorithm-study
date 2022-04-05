#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];

int find(int n) {
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<pair<pair<int, int>, int>> v(E);
	for (int i = 0;i < E;i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;

	sort(v.begin(), v.end(), comp);

	for (int i = 1;i <= V;i++) parent[i] = i;

	int ans = 0;

	for (int i = 0;i < E;i++) {
		int x1 = v[i].first.first;
		int x2 = v[i].first.second;
		int w = v[i].second;

		int p1 = find(x1);
		int p2 = find(x2);

		if (p1 == p2) continue;
		parent[p2] = p1;
		ans += w;
	}

	cout << ans;
}
