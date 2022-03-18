#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int arr[51][51];
int copyArr[51][51];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

/*

2022.3.18

미세먼지는 동시에 확산이 되므로 BFS를 통해 각 지점별로 지점 주변의 확산 결과를 새로운 배열에 저장한 뒤,
모든 지점에서의 확산 과정이 끝나면 기존 미세먼지가 저장이 된 배열에 새로운 배열의 저장된 값들을 더해서 적용시켜준다.
이후 공기청정기로 인한 8가지 방향에 맞춰서 for문을 통해 배열에 저장된 값들을 이동을 시켜준다.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C, T;
	cin >> R >> C >> T;

	int up = -1, down = -1;

	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (up == -1) up = i;
				else down = i;
			}
		}
	}

	queue<pair<int, int>> queue;

	while (T--) {

		for (int i = 1;i <= R;i++) {
			for (int j = 1;j <= C;j++) {
				if (arr[i][j] != -1 && arr[i][j] != 0) {
					queue.push({ i,j });
				}
			}
		}
		
		while (!queue.empty()) {

			int nowI = queue.front().first;
			int nowJ = queue.front().second;
			int val = arr[nowI][nowJ] / 5;
			int cnt = 0;
			queue.pop();

			for (int i = 0;i < 4;i++) {
				int nextI = nowI + moveI[i];
				int nextJ = nowJ + moveJ[i];
				if (nextI < 1 || nextJ < 1 || nextI > R || nextJ > C) continue;
				if (arr[nextI][nextJ] == -1) continue;
				copyArr[nextI][nextJ] += val;
				cnt++;
			}

			arr[nowI][nowJ] -= (val * cnt);
		}

		for (int i = 1;i <= R;i++) {
			for (int j = 1;j <= C;j++) {
				arr[i][j] += copyArr[i][j];
			}
		}

		memset(copyArr, 0, sizeof(copyArr));

		for (int i = up-2;i >=1;i--) {
			arr[i + 1][1] = arr[i][1];
		}

		for (int i = 2;i <= C; i++) {
			arr[1][i - 1] = arr[1][i];
		}

		for (int i = 2;i <= up;i++) {
			arr[i-1][C] = arr[i][C];
		}

		for (int i = C - 1;i >= 2;i--) {
			arr[up][i + 1] = arr[up][i];
		}


		for (int i = down + 2;i <= R;i++) {
			arr[i - 1][1] = arr[i][1];
		}

		for (int i = 2;i <= C;i++) {
			arr[R][i - 1] = arr[R][i];
		}

		for (int i = R - 1;i >= down;i--) {
			arr[i + 1][C] = arr[i][C];
		}

		for (int i = C - 1;i >= 2;i--) {
			arr[down][i + 1] = arr[down][i];
		}

		arr[up][2] = 0;
		arr[down][2] = 0;
	}


	int sum = 0;
	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			if (arr[i][j] <= 0) continue;
			sum += arr[i][j];
		}
	}

	cout << sum;

}
