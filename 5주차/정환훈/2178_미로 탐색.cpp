#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/07
    아이디어 : 비슷하게 parsing 후 bfs로 길찾기
    check에는 시작점으로부터 이동한 횟수

*/

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1,-1 };
int check[101][101] = {0,}; // 시작점으로부터의 이동 횟수
int** map;
bool** visited;
int n;
int m;

void bfs(int x, int y) {

	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));



	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = dx[i] + x;
			int new_y = dy[i] + y;
			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && map[new_x][new_y] == 1) {
				if (visited[new_x][new_y] == false) {
					check[new_x][new_y] = check[x][y] + 1;
					visited[new_x][new_y] = true;
					q.push(make_pair(new_x, new_y));
				}
			}
		}


	}


}


int main() {

	cin >> n >> m;

	vector<string> s(n, "");
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	map = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		visited[i] = new bool[m];
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = s[i][j] - '0';
			visited[i][j] = false;
		}
	}

	visited[0][0] = true;
	bfs(0, 0);

	cout << check[n - 1][m - 1] + 1;


	return 0;
}



