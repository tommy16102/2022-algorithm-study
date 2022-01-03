#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
    푼 날짜 : 2021/08/08
    아이디어 : 어떻게든 좌표 구해서 초기화 한다음 각 영역에 대한 dfs

*/


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int m; int n; int k;
int** map;
bool** visited;
int area = 0;

void dfs(int x, int y) {

	visited[x][y] = true; // 방문
	area++;
	for (int i = 0; i < 4; i++) { // 갈 수 있는 모든 경우의 수
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) { // 인덱스 안 벗어나고
			if (visited[next_x][next_y] == false && map[next_x][next_y] == 0) { // 갈 수 있으면
				dfs(next_x, next_y);
			}
		}

	}

}

int main() {



	cin >> m >> n >> k;
	map = new int* [m];
	visited = new bool* [m];
	for (int i = 0; i < m; i++) { // 동적할당
		map[i] = new int[n];
		visited[i] = new bool[n];
	}

	for (int i = 0; i < m; i++) { // 초기화
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			map[i][j] = 0;
		}
	}


	for (int i = 0; i < k; i++) { // k*2개 쌍의 좌표
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j < x2; j++) { // xy좌표가 내가 생각하는거랑 반대엿음
			for (int k = y1; k < y2; k++) {
				visited[k][j] = true;
				map[k][j] = 1;
			}
		}
	}

	vector<int> result;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				area = 0;
				dfs(i, j);
				result.push_back(area);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}



