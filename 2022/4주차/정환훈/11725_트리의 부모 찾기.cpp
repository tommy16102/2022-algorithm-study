#include <bits/stdc++.h>
using namespace std;
int n;
int p[100001];
vector<int> child[100001];
void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a; int b;
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
	}
}

void solve() {

	queue<int> q;
	for (int i = 0; i < child[1].size(); i++) { // 1이 루트
		q.push(child[1][i]); // 1과 연결된 애들
		p[child[1][i]] = 1; // 부모 1로 처리
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < child[now].size(); i++) { // 현재 노드와 연결된 아이들
			if (p[child[now][i]] == 0) { // 부모가 0일 때(아직안정해짐)
				q.push(child[now][i]); // 큐에 추가
				p[child[now][i]] = now; // 부모 정해주기
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << p[i] << '\n';
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