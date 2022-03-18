#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

/*

2022.3.18

각 지점에서 상하좌우에 위치한 지점 중 인구의 수 차이가 R, C 사이여서 국경선을 열 수 있는 지점을 큐에 넣어
BFS 탐색을 하면서 추가적으로 벡터에도 지점을 넣어준다.
BFS 탐색이 끝날 때마다 벡터에 저장된 지점들을 대상으로 인구의 수를 업데이트 해준다.

*/

int arr[51][51];
bool visited[51][51];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L, R;
	cin >> N >> L >> R;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;

	while (1) {
		bool open = false;

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (visited[i][j]) continue;
				visited[i][j] = 1;
				queue<pair<int, int>> queue;
				vector<pair<int, int>> v;
				queue.push({ i, j });
				v.push_back({ i,j });


				while (!queue.empty()) {
					int nowI = queue.front().first;
					int nowJ = queue.front().second;
					int nowVal = arr[nowI][nowJ];
					queue.pop();
					for (int x = 0;x < 4;x++) {
						int newI = nowI + moveI[x];
						int newJ = nowJ + moveJ[x];
						if (newI < 0 || newJ < 0 || newI >= N || newJ >= N) continue;
						if (visited[newI][newJ]) continue;
						int nextVal = arr[newI][newJ];
						int diff = abs(nowVal - nextVal);
						if (diff >= L && diff <= R) {
							queue.push({ newI, newJ });
							v.push_back({ newI, newJ });
							visited[newI][newJ] = 1;
						}
					}
				}

				if (v.size() > 1) open = true;

				int sum = 0;
				for (int i = 0;i < v.size();i++) {
					sum += arr[v[i].first][v[i].second];
				}

				int div = sum / v.size();
				for (int i = 0;i < v.size();i++) arr[v[i].first][v[i].second] = div;
				
			}
		}

		memset(visited, 0, sizeof(visited));

		if (open) ans++;
	  else {
			cout << ans;
			return 0;
		}
	}
}
