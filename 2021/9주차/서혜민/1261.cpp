#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

/*

2021.09.09. 

(1,1)이 시작점이므로 queue에 넣은 뒤, 최단 경로(벽부신횟수 가장 적음)의 길이인 dist는 모두 int_max로 초기화한뒤,
시작점 dist[1][1]만 0으로 설정한다. 
이후, queue가 빌 때까지 queue에서 꺼낸 x,y좌표를 기준으로 상,하,좌,우를 이동한 좌표가 해당 미로 안에 있으며,
이동한 장소가 1일 때는 벽을 부셔야하므로 최단 경로를 구하기 위해 이동하기 전 좌표의 dist값에 1을 더한 값보다 처음에 int_max로
초기화한 새로운 좌표의 dist값이 더 크다면 이 좌표의 dist값을 이전 좌표의 dist값에 +1한 값으로 바꿔주며 큐에 넣어주고,
0일 때는 벽을 부실 필요가 없으므로 이전의 좌표의 dist값보다 작을 때만, 해당 dist좌표를 이전 dist 값으로
설정한 뒤, queue에 넣어준다.

결국, 더 최단 경로의 값을 찾게 되면 계속 queue에 넣어주는 방식이므로, 더이상의 최단 경로를 찾지 못하면
이 반복문은 끝나게 된다.

*/

string maze[101];
int dist[101][101];
int moveM[4] = { 0,1,0,-1 };
int moveN[4] = { -1,0,1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	for (int i = 1;i <= N;i++) {
		cin >> maze[i];
		maze[i] = ' ' + maze[i];
	}

	queue<pair<int, int>> queue;
	queue.push({ 1,1 });
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			dist[i][j] = INT_MAX;
		}
	}
	dist[1][1] = 0;
	
	while (!queue.empty()) {
		int m = queue.front().second;
		int n = queue.front().first;
		queue.pop();
		for (int i = 0;i < 4;i++) {
			int newM = m + moveM[i];
			int newN = n + moveN[i];
			if (newM >= 1 && newM <= M && newN >= 1 && newN <= N ) {
				if (maze[newN][newM] == '1' && dist[newN][newM]>(dist[n][m]+1)) {
					dist[newN][newM] = dist[n][m] + 1;
					queue.push({ newN,newM });
				}
				else if (maze[newN][newM] == '0' && dist[newN][newM] > dist[n][m]) {
					dist[newN][newM] = dist[n][m];
					queue.push({ newN,newM });
				}
				
			}
			
		}
	}
	cout << dist[N][M] << endl;
}
