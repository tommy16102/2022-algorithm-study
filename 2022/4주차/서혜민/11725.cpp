#include <iostream>
#include <vector>
using namespace std;

/*

2022.2.2

DFS를 통해 연결된 노드간의 부모,자식 관계를 parent배열에 저장.

*/

int N;
vector<int> v1[100001];
int parent[100001];
bool visited[100001];

void dfs(int node) {
	for (int i = 0;i < v1[node].size();i++) {
		int n = v1[node][i];
		if (!visited[n]) {
			parent[n] = node;
			visited[n] = 1;
			dfs(n);
			visited[n] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1;i < N;i++) {
		int node1, node2;
		cin >> node1 >> node2;
		v1[node1].push_back(node2);
		v1[node2].push_back(node1);
	}

	visited[1] = 1;
	dfs(1);
	
	for(int i=2;i<=N;i++) cout<<parent[i]<<'\n';
}
