/*******************************************************************
Algorithm Study
Baekjoon BFS/DFS
2210 숫자판 점프
2021/08/05 이호준
# 아이디어
1. DFS로 모든지점에서 시작하면 되지않을까? 되었다..
집합을(set) 이용하면 해당 값들을 빠르게 있는지 없는지 확인할 수 있다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int count, vector<vector<int>> &map, int x, int y, int value);

unordered_set<int> set;
int dx[4] = { 0, 0, - 1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> map(5, vector<int>(5, 0));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	//for (auto a : map) {
	//	for (auto b : a)
	//		cout << b << " ";
	//	cout << "\n";
	//}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(0, map, i, j, 0);
		}
	}
	//for (auto a : set)
	//	cout << a << endl;
	cout << set.size();
	return 0;
}

void dfs(int count, vector<vector<int>>& map, int x, int y, int value)
{
	if (count == 6) {
		if (set.find(value) == set.end()) {
			set.insert(value);
		}
		return;
	}
	value = value * 10 + map[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			dfs(count + 1, map, nx, ny, value);
		}
	}

}
