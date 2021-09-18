#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210830

int parent[100001];
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

	vector<int> path;
	int answer = 0;
	nodes.push_back(make_pair(n, 0));
	visited[n] = true;
	bool flag = false;
	if (n == k) { // 예외처리
		flag = true;
		answer = 1;
	}
	
	while (visited[k] == false) { // 만나기 전까지
		deque<pair<int, int>> next; // 다음 방문 예정인 노드 목록

		for (int i = 0; i < nodes.size(); i++) { // 가야 할 노드 사이즈만큼
			int now = nodes[i].first;
			int move_front = now + 1; // 앞
			int move_back = now - 1; // 뒤
			int tp = 2 * now; // 텔포

			if (move_front <= 100000 && visited[move_front] == false) { // 배열 인덱스 맞고 && 아직 안 방문함?
				next.push_back(make_pair(move_front, tries));
				parent[move_front] = now;
			}
			if (move_back >= 0 && visited[move_back] == false) {
				next.push_back(make_pair(move_back, tries));
				parent[move_back] = now;
			}
			if (tp <= 100000 && visited[tp] == false) {
				next.push_back(make_pair(tp, tries));
				parent[tp] = now;
			}
		}

		nodes.clear(); // 가야 할 노드 다 갔으므로
		for (int i = 0; i < next.size(); i++) { // 다음 노드로 채워주는데
			nodes.push_back(next[i]);
			visited[nodes[i].first] = true; // 다음 노드로 채워주기 전에 방문 처리(왜냐하면 1->2->4에서 1->2로 가는 길이 다양하므로)
			if (nodes[i].first == k) { // 정답 찾음
				int id = nodes[i].first;
				
				while (id != n) { // 뒷추적
					path.push_back(parent[id]);
					id = parent[id];
				}
				answer++;
				break;
			}
		}
		next.clear();
		tries++; // 몇초 걸림?

	}

	cout << tries << endl;
	reverse(path.begin(), path.end()); // 길 뒤집기
	path.push_back(k); // 마지막만 넣어주기
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
}

int main() {

	input();
	solve();
	return 0;
}