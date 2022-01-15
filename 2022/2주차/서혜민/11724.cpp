#include <iostream>
using namespace std;

/*

2021.01.15 서혜민

이차원 배열을 통해 서로 연결관계에 있는 정점들에 1을 저장.
포문을 통해 아직 방문하지 않은 정점부터 해당 정점을 시작점으로
연결관계에 있는 정점을 탐색해나감.
탐색은 연결 관계가 더이상 나타나지 않을 때까지.
이때 연결 요소의 개수는 이러한 탐색을 하는 횟수.  

*/

int N, M;
int arr[1001][1001];
bool visited[1001];

void dfs(int x) {
	visited[x] = 1;
	for (int i = 1;i <= N;i++) {
		if (arr[x][i] && !visited[i]) dfs(i);
	}
}

int main() {
	cin >> N >> M;
	
	int u, v;
	while (M--) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	int count = 0;
	for (int i = 1;i <= N;i++) {
		if (!visited[i]) {
			count++;
			dfs(i);
		}
	}
	cout << count << '\n';
}
