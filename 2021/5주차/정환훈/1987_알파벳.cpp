#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
    푼 날짜 : 2021/08/08
    아이디어 : 백트래킹 이랍니다
*/
int r; int c;
char** map;
bool visited[26] = { false, };
int ct = 1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
static int cnt = 1;
static int ans = 1;


void dfs(int x, int y, char** map, bool visited[], int count) {
	
	ans = max(ans, count); // count는 값이 계속 돌아가므로 max 값은 저장해 둬서 비교해야 한다

	for (int i = 0; i < 4; i++) { // 갈 수 있는 경우의 수 4가지
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < r && ny >= 0 && ny < c) { // 인덱스 안 벗어나고

			if (visited[int(map[nx][ny]) - 'A'] == false) { // 그 곳이 아직 방문한 곳 아닐 시
				visited[int(map[nx][ny]) - 'A'] = true; //
				dfs(nx, ny, map, visited, count + 1); // count+1 한 후 그 곳 방문
				visited[int(map[nx][ny]) - 'A'] = false; // 님들은 신경쓰지 말고 할거 하세요
			}
		}

	}

}

int main() {

	cin >> r >> c;
	char** map = new char* [r];
	for (int i = 0; i < r; i++) {
		map[i] = new char[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	int c = int(map[0][0]) - 'A';
	visited[c] = true; // 시작지점 방문처리
	dfs(0, 0, map, visited, 1);

	cout << ans;

	return 0;
}



