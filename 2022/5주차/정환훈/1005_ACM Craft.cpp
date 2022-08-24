#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int k;
int w;
int cost[1001];
int in[1001];
int times[1001];
vector<int> ins[1001];
vector<int> outs[1001];

void input() {


	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		ins[i].clear();
		outs[i].clear();
		times[i] = 0;
		in[i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		int from;
		int to;
		cin >> from >> to;
		in[to]++;
		ins[to].push_back(from);
		outs[from].push_back(to);
	}
	cin >> w;
}



void solve() {
	queue<int> q;
	for (int i = 1; i <= n; i++) { // 초기에 들어오는 게 없는 친구들 넣어줌
		if (in[i] == 0) {
			q.push(i);
			in[i] = -1;
			times[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < outs[now].size(); i++) { // 현재 노드에서 나가는 애들 하나씩 제거
			int del = outs[now][i]; // 현재 선 제거한 노드
			in[del]--; // del이 들어오는게 하나 줄음
			times[del] = max(times[del], times[now] + cost[del]); // 짓는 시간 = max(선행 노드 지어지는 총 시간 + 해당 노드 지어지는 시간)
			if (in[del] == 0) { // 제거함으로써 현재 노드가 들어오는게 없어졌으면
				in[del] = -1;
				q.push(del); // 큐에 추가
			}

		}
	}


	cout << times[w] << '\n';

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