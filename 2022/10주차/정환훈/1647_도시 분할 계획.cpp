#include <bits/stdc++.h>
using namespace std;

int n;
int m;
vector < pair<int, pair<int, int>>> v;
int parent[100001];
int findParent(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = findParent(parent[x]);
}
void uni(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	parent[y] = x;
}


void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from;
		int to;
		int cost;
		cin >> from >> to >> cost;
		v.push_back({ cost,{from,to} });
	}
}

void solve() {

	// 초기에 자신의 부모를 자신으로 설정
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	sort(v.begin(), v.end());

	// 모든 간선 정보에 대하여
	int ans = 0;
	int maxCost = 0;
	for (int i = 0; i < v.size(); i++) {
		pair<int, int> now = v[i].second;
		// 사이클 검사
		if (findParent(now.first) != findParent(now.second)) {
			// 사이클 아닐 시 결합, 유지비 제일 큰 길 찾아내기
			uni(now.first, now.second);
			maxCost = max(v[i].first, maxCost); 
			ans += v[i].first;
		}
	}
	ans -= maxCost; // 전체 도로에서 가장 비싼 도로 빼기
	cout << ans;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}