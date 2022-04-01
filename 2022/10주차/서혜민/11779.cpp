#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 1000 * 100000 + 1
using namespace std;

vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[1001];
int prior[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	int A, B;
	cin >> A >> B;

	for (int i = 1;i <= n;i++) dist[i] = MAX;

	pq.push({ 0, A });
	dist[A] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (val > dist[now]) continue;
		for (int i = 0;i < v[now].size();i++) {
			int next = v[now][i].first;
			int nextVal = v[now][i].second;
			if (dist[next] > val + nextVal) {
				dist[next] = val + nextVal;
				prior[next] = now;
				pq.push({ dist[next], next });
			}
		}
	}

	cout << dist[B] << endl;

	vector<int> ans;
	while (B) {
		ans.push_back(B);
		B = prior[B];
	}

	cout << ans.size() << endl;

	for (int i = 0;i < ans.size();i++) cout << ans[ans.size() - i - 1] << ' ';

}
