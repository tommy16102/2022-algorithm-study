#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/05
    아이디어 : dx[i], dy[i]로 갈 수 있는 방향 모두 표시 후
    그 지점으로 갈 수 있는지를 판단한 후 갈 수 있으면 dfs 실행
    끝까지 도달하면 push

*/


vector<int> answers;
int numbers[5][5];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void dfs(int turn, int num, int x, int y) {

	if (turn == 6) { // 점프 다 뛰었으면
		answers.push_back(num); // 저장
		return;
	}

	for (int k = 0; k < 4; k++) { // 인접한 곳으로 이동
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			dfs(turn + 1, num * 10 + numbers[nx][ny], nx, ny);
		}
	}


}

int main() {

	// input
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> numbers[i][j];
		}
	}
	// input
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(1, numbers[i][j], i, j);
		}
	}

	sort(answers.begin(), answers.end());
	answers.erase(unique(answers.begin(), answers.end()), answers.end());

		cout << answers.size() << endl;
	

	return 0;
}

