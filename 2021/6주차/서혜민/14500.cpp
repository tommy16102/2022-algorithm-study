#include <iostream>
using namespace std;

/*

2021.08.16 서혜민

ㅗ ㅜ ㅓ ㅏ 는 방문했던 곳을 다시는 방문하지 않는 dfs를 통해서 만들어낼 수가 없으므로,
이 도형들은 따로 getSum이라는 함수를 통해서 합을 구한다.

*/


int arr[501][501];
bool visited[501][501];
int moveS[4] = { -1,0,1,0 };
int moveG[4] = { 0,1,0,-1 };

int N, M;
int max = 0;

void makeTetromino(int sero, int garo, int count, int sum) {
	if (count == 4) {
		if (sum > ::max) ::max = sum;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int nSero = sero + moveS[i];
		int nGaro = garo + moveG[i];
		if (nSero >= 0 && nSero < N && nGaro >= 0 && nGaro < M && !visited[nSero][nGaro]) {
			visited[nSero][nGaro] = 1;
			makeTetromino(nSero, nGaro, count + 1, sum + arr[nSero][nGaro]);
			visited[nSero][nGaro] = 0;
		}
	}
}

void getSum(int x, int y) {
	int sum = 0;
	sum = arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
	if (sum > ::max) ::max = sum;
}

void getSum2(int x, int y) {
	int sum = 0;
	sum = arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y];
	if (sum > ::max) ::max = sum;
}

void getSum3(int x, int y) {
	int sum = 0;
	sum = arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x][y + 2];
	if (sum > ::max) ::max = sum;
}

void getSum4(int x, int y) {
	int sum = 0;
	sum = arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y + 1];
	if (sum > ::max) ::max = sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			visited[i][j] = 1;
			makeTetromino(i, j, 1, arr[i][j]);
			visited[i][j] = 0;
			if (i <= (N - 2) && j <= (M - 3)) {
				getSum(i, j);
				getSum3(i, j);
			}
			if (i <= (N - 3) && j <= (M - 2)) {
				getSum2(i, j);
				getSum4(i, j);
			}
		}
	}
	cout << ::max << endl;
}
