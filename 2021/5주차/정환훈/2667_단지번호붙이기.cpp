#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/07
    아이디어 : dfs로 갈 수 있는 곳 파악해서 한 번의 dfs마다 2, 3, 4, 5...로 만들고 그 영역 넓이 다 세기

*/

int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1,-1 };
int** map;
bool** visited;
int n;
int t = 2;

void dfs(int x, int y) {

	if (map[x][y] == 0) // 갈 수 없는 곳이면 return
		return;
	if (visited[x][y] == true) // 와 본 곳이면 return
		return;

	visited[x][y] = true; // 방문 처리
	
	for (int i = 0; i < 4; i++) { // 모든 경우의 수
		int new_x = dx[i] + x;
		int new_y = dy[i] + y;
		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) { // 인덱스 안 벗어나면
			map[x][y] = t;
			dfs(new_x, new_y); // 탐색 진행
		}
	}	

}


int main() {


	// input
	
	cin >> n;

	vector<string> s(n, "");
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	map = new int*[n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		visited[i] = new bool[n];
	}

	// input 

	// parsing
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = s[i][j] - '0';
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				dfs(i, j); 
				t++;
			}

		}
	}


	vector<int> result;
	for (int i = 2; i < t; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (map[j][k] == i) {
					temp++;
				}
			}

		}

		result.push_back(temp);
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}


	return 0;
}

