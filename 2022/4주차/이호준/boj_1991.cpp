/*******************************************************************
Algorithm Study
Baekjoon OJ Tree
1991 트리순회
2022/02/08 이호준
# 아이디어
1. root가 명시되어있어 graph를 만들기 dfs로 탐색
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void dfs(char root, int type, vector<vector<char>> &map) {
	if (type == 0) {
		cout << root;
		if (map[root - 'A'][0] != '.') {
			dfs(map[root - 'A'][0], type, map);
		}
		if (map[root - 'A'][1] != '.') {
			dfs(map[root - 'A'][1], type, map);
		}
	}
	else if (type == 1) {
		if (map[root - 'A'][0] != '.') {
			dfs(map[root - 'A'][0], type, map);
		}
		cout << root;
		if (map[root - 'A'][1] != '.') {
			dfs(map[root - 'A'][1], type, map);
		}
	}
	else if (type == 2) {
		if (map[root - 'A'][0] != '.') {
			dfs(map[root - 'A'][0], type, map);
		}
		if (map[root - 'A'][1] != '.') {
			dfs(map[root - 'A'][1], type, map);
		}
		cout << root;
	}
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	vector<vector<char>> tree(n, vector<char>(2, ' '));

	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		tree[x - 'A'][0] = y;
		tree[x - 'A'][1] = z;
	}

	for (int i = 0; i < 3; i++) {
		dfs('A', i, tree);
		cout << "\n";
	}

	return 0;
}