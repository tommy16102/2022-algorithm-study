/*******************************************************************
Algorithm Study
Baekjoon OJ DP
11725 트리의 부모 찾기
2022/02/08 이호준
# 아이디어
1. DFS를 이용해 부모 찾기..
*******************************************************************/
#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;
int N;
int arr[MAX];
bool visited[MAX];
vector<int> map[MAX];

void dfs(int root) {

	visited[root] = true;

	for (auto a : map[root]) {
		int next = a;
		if (!visited[next]) {
			arr[next] = root;
			dfs(next);
		}
	}
}

int main(void) {
	
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y; 
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}
	
	dfs(1); 
	
	for (int i = 2; i <= N; i++) 
		cout << arr[i] << "\n";

	return 0;
}
