#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> V[10001];
int ans[10001];
bool visited[10001];
int maxAns = 0;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		V[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		if (V[i].empty()) continue;
		queue<int> q;
		visited[i] = 1;
		q.push(i);
		int cnt = 0;
		while (!q.empty()) {
			int now = q.front();
			cnt++;
			q.pop();
			for (int j = 0; j < V[now].size(); j++) {
				int next = V[now][j];
				if (!visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
		ans[i] = cnt;
		maxAns = max(maxAns, cnt);
		for (int j = 1; j <= N; j++) visited[j] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i] == maxAns) cout << i << ' ';
	}
}
