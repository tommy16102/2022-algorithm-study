#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

/*
2022.1.1 서혜민

출발점인 fromX, fromY부터 BFS 방식으로 나이트가 이동할 수 있는 경로를 저장한 moveX, moveY배열 내 값들로
이미 방문하지 않은 다음 경로를 계속 queue에 넣어주면서, 추가적으로 0으로 초기값을 저장한 mCount배열의 출발 위치에서부터
다음 위치로 갈 때마다 이전 위치의 값에 +1한 값을 mCount의 다음 위치의 값에 저장을 해준다.
이후, queue에서 꺼낸 값이 toX, toY가 되면 종료가 되며 해당 mCount에 저장된 값이 최소 경로의 길이가 된다.
*/

int moveX[8] = { 1,2,2,1,-1,-2,-2,-1 };
int moveY[8] = { 2,1,-1,-2,-2,-1,1,2 };
bool visited[301][301];
int mCount[301][301];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int L;
		cin >> L;

		int fromX, fromY, toX, toY;
		cin >> fromX >> fromY >> toX >> toY;

		queue<pair<int, int>> queue;
		queue.push({ fromX, fromY });
		mCount[fromX][fromY] = 0;

		while (!queue.empty()) {
			int x = queue.front().first;
			int y = queue.front().second;

			if (x == toX && y == toY) {
				cout << mCount[x][y] << '\n';
				break;
			}
			queue.pop();

			for (int i = 0;i < 8;i++) {
				int newX = x + moveX[i];
				int newY = y + moveY[i];
				if (newX >= 0 && newX < L && newY >= 0 && newY < L && !visited[newX][newY]) {
					queue.push({ newX,newY });
					visited[newX][newY] = 1;
					mCount[newX][newY] = mCount[x][y] + 1;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(mCount, 0, sizeof(mCount));
	}
}
