#include <iostream>
#include <queue>
using namespace std;

/*

2021.08.23 서혜민

bfs를 통해 1부터 연결된 컴퓨터를 탐색할때마다 개수 하나씩 증가.

*/

int computers[101][101];
bool visited[101];

int main() {
	int cCount;
	int cSsang;
	cin >> cCount >> cSsang;

	int x, y;
	while (cSsang--) {
		cin >> x >> y;
		computers[x][y] = 1;
		computers[y][x] = 1;
	}

	int count = 0;
	queue<int> queue;
	queue.push(1);
	visited[1] = 1;
	while (!queue.empty()) {
		int index = queue.front();
		queue.pop();
		for (int i = 1;i <= cCount;i++) {
			if (!visited[i] && computers[index][i]) {
				visited[i] = 1;
				queue.push(i);
				count++;
			}
		}
	}

	cout << count << endl;
}
