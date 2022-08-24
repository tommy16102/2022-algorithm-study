#include <bits/stdc++.h>
using namespace std;

int v; int e;
vector < pair<int, pair<int, int>>> edge_info;
int parent[10001];

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}


void uni(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	parent[y] = x;
}

void input() {
	cin >> v >> e;

	// 초기 자신의 부모 = 자기 자신으로 세팅
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int from;
		int to;
		int cost;
		cin >> from >> to >> cost;
		edge_info.push_back({ cost,{from,to} });
	}
}

void solve() {

	int ans = 0;
	// edge_info = <cost, <from, to>>
	// cost 기준으로 정렬
	sort(edge_info.begin(), edge_info.end());
	// 모든 간선 정보에 대하여
	for (int i = 0; i < edge_info.size(); i++) {
		// cycle 검사 아니면 추가
		// cycle 검사 : edge_info 의 from과 to가 동일한 부모인지?

		pair<int, int> now_info = edge_info[i].second;

		if (find_parent(now_info.first) != find_parent(now_info.second)) { 
			// 간선 잇기
			uni(now_info.first, now_info.second);
			ans += edge_info[i].first;
		}
	}
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