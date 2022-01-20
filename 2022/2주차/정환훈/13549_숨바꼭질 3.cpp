#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int n;
int k;
int answer = 0;
deque<pair<int, int>> nodes; // {현재 위치, 시도 횟수}


void input() {
	cin >> n >> k;
}

void solve() { // 이동하는 길에 tp를 최대한 많이 쓰면 좋으므로 deque에서 tp를 위에다 넣고 나머지를 뒤에다 넣는다

	nodes.push_back(make_pair(n, 0));
	visited[n] = true;
	int answer = 1111;
	while (!nodes.empty()) {
		int now = nodes.front().first; // 현재 위치
		int tries = nodes.front().second; // 시도 횟수
		nodes.pop_front();
		if (now == k) { // 방문 시 break
			answer = tries;
			break;
		}
		int mf = now + 1; // 앞
		int mb = now - 1; // 뒤
		int tp = now * 2; // tp

		if (tp <= 100000 && visited[tp] == false) { // tp 우선순위
			nodes.push_front({ tp, tries });
			visited[tp] = true;
		}
		if (mf <= 100000 && visited[mf] == false) {
			nodes.push_back({ mf, tries + 1 });
			visited[mf] = true;
		}
		if (mb >= 0 && visited[mb] == false) {
			nodes.push_back({ mb, tries + 1 });
			visited[mb] = true;
		}


	}

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int n;
int k;
int answer = 0;
deque<pair<int, int>> nodes; // {현재 위치, 시도 횟수}


void input() {
	cin >> n >> k;
}

void solve() { // 이동하는 길에 tp를 최대한 많이 쓰면 좋으므로 deque에서 tp를 위에다 넣고 나머지를 뒤에다 넣는다

	nodes.push_back(make_pair(n, 0));
	visited[n] = true;
	int answer = 1111;
	while (!nodes.empty()) {
		int now = nodes.front().first; // 현재 위치
		int tries = nodes.front().second; // 시도 횟수
		nodes.pop_front();
		if (now == k) { // 방문 시 break
			answer = tries;
			break;
		}
		int mf = now + 1; // 앞
		int mb = now - 1; // 뒤
		int tp = now * 2; // tp

		if (tp <= 100000 && visited[tp] == false) { // tp 우선순위
			nodes.push_front({ tp, tries });
			visited[tp] = true;
		}
		if (mf <= 100000 && visited[mf] == false) {
			nodes.push_back({ mf, tries + 1 });
			visited[mf] = true;
		}
		if (mb >= 0 && visited[mb] == false) {
			nodes.push_back({ mb, tries + 1 });
			visited[mb] = true;
		}


	}

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}