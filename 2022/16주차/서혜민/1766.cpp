#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[32001];
int cnt[32001];
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		cnt[B]++;
	}

	for (int i = 1; i <= N; i++) if (cnt[i] == 0) pq.push(i);

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		cout << now << ' ';
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			cnt[next]--;
			if (cnt[next] == 0) pq.push(next);
		}
	}
}
