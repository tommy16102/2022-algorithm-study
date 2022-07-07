#include <iostream>
#include <queue>
using namespace std;

int arr[102][102];
bool visited[102][102];
int moveOdd[6][2] = { {0, -1}, {1,-1},{1,0},{1,1},{0,1},{-1,0} };
int moveEven[6][2] = { {-1,-1},{0,-1},{1,0},{0,1},{-1,1},{-1,0} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int W, H;
	cin >> W >> H;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> arr[i][j];
		}
	}
	
	int ans = 0;

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();

		if (nowI % 2 == 1) {
			for (int i = 0; i < 6; i++) {
				int nextI = nowI + moveOdd[i][1];
				int nextJ = nowJ + moveOdd[i][0];
				if (nextI < 0 || nextJ < 0 || nextI > H + 1|| nextJ > W + 1) continue;
				if (visited[nextI][nextJ]) continue;
				if (arr[nextI][nextJ] == 0) {
					q.push({ nextI, nextJ });
					visited[nextI][nextJ] = 1;
				}
				else ans++;
			}
		}
		else {
			for (int i = 0; i < 6; i++) {
				int nextI = nowI + moveEven[i][1];
				int nextJ = nowJ + moveEven[i][0];
				if (nextI < 0 || nextJ < 0 || nextI > H + 1 || nextJ > W + 1) continue;
				if (visited[nextI][nextJ]) continue;
				if (arr[nextI][nextJ] == 0) {
					q.push({ nextI, nextJ });
					visited[nextI][nextJ] = 1;
				}
				else ans++;
			}
		}
	}

	cout << ans;
}