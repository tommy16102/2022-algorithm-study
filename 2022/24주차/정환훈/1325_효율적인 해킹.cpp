#include <bits/stdc++.h>
using namespace std;

int n; int m;
vector<int> trusted[10001];
bool check[10001];
vector<pair<int, int>> p;
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from; int to;
		cin >> to >> from;
		trusted[from].push_back(to);
	}
}

void bfs(int start) {
	memset(check, false, sizeof(check));
	int hacked = 0;
	queue<int> q;
	check[start] = true;
	q.push(start);
	int test = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < trusted[now].size(); i++) {
			if (!check[trusted[now][i]]) {
				check[trusted[now][i]] = true;
				q.push(trusted[now][i]);
				hacked++;
			}
		}
	}
	p.push_back({ hacked, start });
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first > b.first;
}

void solve() {
	
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	sort(p.begin(), p.end(), cmp);
	vector<int> ans;
	int m = p[0].first;
	for (int i = 0; i < p.size(); i++) {
		if (m == p[i].first)
			ans.push_back(p[i].second);
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}


}
	


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}
