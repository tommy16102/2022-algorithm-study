#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> V[100001];
bool visited[10001];

bool bfs(int w, int f1, int f2) {
	queue<int> q;
	q.push(f1);
	visited[f1] = 1;
	while (!q.empty()) {
		int now = q.front();
		if (now == f2) return true;
		q.pop();
		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first;
			int nextW = V[now][i].second;
			if (visited[next]) continue;
			if (nextW < w) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int maxW = 0;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		V[A].push_back({ B, C });
		V[B].push_back({ A, C });
		maxW = max(maxW, C);
	}

	int f1, f2;
	cin >> f1 >> f2;

	int left = 0, right = maxW;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (bfs(mid, f1, f2)) left = mid + 1;
		else right = mid - 1;
		for (int i = 1; i <= N; i++) visited[i] = 0;
	}

	cout << right;

}
