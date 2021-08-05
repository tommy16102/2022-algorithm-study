#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*

2021.08.09 서혜민

입력받은 간선을 arr에 저장 후,
V를 시작으로 dfs는 재귀, bfs는 queue를 통해 탐색을 실행.

*/


int arr[1001][1001];
bool visited[1001] = { 0, };
int N, M, V;

void dfs(int n) {
	cout << n << ' ';
	for (int i = 1;i <= N;i++) {
		if (n!=i && arr[n][i] != 0 && !visited[i]) {
			visited[i] = 1;
			dfs(i);
}
	}
	return;
}

void bfs(int n) {
	queue<int> queue;
	queue.push(n);
	visited[n] = 1;
	while (!queue.empty()) {
		int num = queue.front();
		cout << num << ' ';
		queue.pop();
		for (int i = 1;i <= N;i++) {
			if (num != i && arr[num][i] != 0 && !visited[i]) {
				visited[i] = 1;
				queue.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;

	int x, y;
	while (M--) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	visited[V] = 1;
	dfs(V);
	memset(visited, 0, sizeof(visited));
	cout << endl;

	bfs(V);
	cout << endl;
}