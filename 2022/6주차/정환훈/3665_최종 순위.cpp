#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int m;
int adj[501][501];
int in[501];
int order[501]; // order[i] = 작년에 i등을 한 팀의 번호
void input() {
	for (int i = 0; i < 501; i++) {
		in[i] = 0;
		for (int j = 0; j < 501; j++) {
			adj[i][j] = 0;
		}
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> order[i];
	}

	// 1등->2등 1등->3등 ...
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			adj[order[i]][order[j]] = 1;
			in[order[j]]++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) { // 그래프 간선 방향 바꿔주기
		int a;
		int b;
		cin >> a >> b;
		if (adj[a][b]) {
			adj[a][b] = 0;
			adj[b][a] = 1;
			in[b]--;
			in[a]++;
		}
		else {
			adj[b][a] = 0;
			adj[a][b] = 1;
			in[a]--;
			in[b]++;
		}
	}
}

void solve() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			q.push(i);
	}

	vector<int> answer;
	while (!q.empty()) {
		if (q.size() > 1) { // 순서를 정할 수 없음(동시 완료가 두개 이상)
			cout << "?\n";
			return;
		}
		int cur = q.front(); // 위상정렬 과정
		q.pop();
		answer.push_back(cur);
		for (int next = 1; next <= n; next++) {
			if (adj[cur][next]) {
				in[next]--;
				if (!in[next]) {
					q.push(next);
				}
			}
		}
	}
	
	if (answer.size() != n) { // 사이클이 생김
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << '\n';
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}
	return 0;
}