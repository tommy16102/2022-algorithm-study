#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


bool visited[100001] = { false, };
int n;
int k;
int tries = 0;
deque<pair<int, int>> nodes;


void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
}


void solve() {

	nodes.push_back(make_pair(n, 0));
	visited[n] = true;
	while (visited[k] == false) {
		deque<pair<int, int>> next;
		for (int i = 0; i < nodes.size(); i++) {
			int now = nodes[i].first;
			int move_front = now + 1;
			int move_back = now - 1;
			int tp = 2 * now;
			if (move_front <= 100000 && visited[move_front] == false) {
				visited[move_front] = true;
				next.push_back(make_pair(move_front, tries));

			}
			if (move_back >= 0 && visited[move_back] == false) {
				visited[move_back] = true;
				next.push_back(make_pair(move_back, tries));
			}
			if (tp <= 100000 && visited[tp] == false) {
				visited[tp] = true;
				next.push_back(make_pair(tp, tries));
			}
		}

		nodes.clear();
		for (int i = 0; i < next.size(); i++) {
			nodes.push_back(next[i]);
		}
		next.clear();
		tries++;

	}

	cout << tries;
}

int main() {

	input();
	solve();
	return 0;
}