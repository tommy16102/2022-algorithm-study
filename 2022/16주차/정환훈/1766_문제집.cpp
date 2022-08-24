#include <bits/stdc++.h>
using namespace std;

int n; int m;
int in[32001];
vector<int> adj[32001];
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; int b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
}


void solve() {
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < adj[cur].size(); i++) {
			in[adj[cur][i]]--;
			if (in[adj[cur][i]] == 0)
				q.push(adj[cur][i]);
		}
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