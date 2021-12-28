#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n; int m; int start;

/*
    푼 날짜 : 2021/08/05
    아이디어 : DFS - 재귀 BFS - 큐

*/

void dfs(vector<int>*& graph, bool* visited, int x) { // dfs

	visited[x] = true; // 밟은 부분 방문 처리
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) { // 해당 부분이 갖고 있는 간선의 개수만큼 반복
		int y = graph[x][i]; // 다음 길
		if (visited[y] == false) { // 다음 길을 아직 안 갔으면
			dfs(graph, visited, y); // dfs
		}
	}


}

void bfs(vector<int>*& graph, bool* visited, int st) {

	queue<int> q;
	q.push(st); // 첫 노드를 queue에 삽입
	visited[st] = true; // 첫 노드를 방문 처리

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		// 큐에서 하나의 원소를 뽑아 출력
		int x = q.front();
		q.pop();
		cout << x << ' ';
		// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {

	
	// input
	cin >> n >> m >> start;


	// init
	vector<int>* graph = new vector<int>[n + 1];

	for (int i = 0; i < m; i++) {
		int from; int to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	// init
	bool* visited = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) {
		visited[i] = false;
	}



	// 오름차순 배치
	for (int i = 1; i < n + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	// dfs 출력
	dfs(graph, visited, start);
	cout << endl;

	for (int i = 0; i < n + 1; i++) {
		visited[i] = false;
	}

	// bfs 출력
	bfs(graph, visited, start);



	return 0;
}

