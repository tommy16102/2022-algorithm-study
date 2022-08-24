#include <bits/stdc++.h>
using namespace std;

int n;
int m;
vector<int> nodes[32001];
vector<pair<int, int>> in; // {인덱스(숫자번호), 들어오는 간선 개수}

void input() {

	cin >> n >> m;
	in.push_back({-1, -1});

	for (int i = 1; i <= n; i++) {
		in.push_back({0, i});
	}

	for (int i = 1; i <= m; i++) {
		int from; int to;
		cin >> from >> to;
		nodes[from].push_back(to); // 나가는 노드 모음
		in[to].first++;
	}
}

void solve() {

	
	/*

		위상정렬 하는법
		1) 들어오는 진입간선의 개수와 진출하는 간선의 목록의 배열을 만든다
		2) 진입간선의 개수가 0인 애들을 queue에 넣는다.
		3) queue에 넣은 애들 방문하면서 해당 애들이 진출하는 애들의 진입간선 개수를 1 줄인다(해당 노드의 나가는 간선 삭제)
	*/

	queue<int> q;
	for (int i = 0; i < in.size(); i++) {
		if (in[i].first == 0) {  // 들어오는 애들이 0인 노드를 큐에 넣음
			q.push(in[i].second);
			in[i].first = -1;
		}
	}

	while (!q.empty()) {
		int now = q.front(); // 하나 뽑아서
		cout << now << " ";
		q.pop();
		for (int i = 0; i < nodes[now].size(); i++) { // 해당 노드에서 빠져나가는 모든 간선 제거
			int del = nodes[now][i];
			in[del].first--;
			
		}

		for (int i = 0; i < in.size(); i++) {
			if (in[i].first == 0) { // 0이 된 애들 다시 큐에 넣어줌
				q.push(in[i].second);
				in[i].first = -1;
			}
		}
	}

	for (int i = 0; i < in.size(); i++) {
		if (in[i].first != -1) {
			cout << in[i].second << ' ';
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