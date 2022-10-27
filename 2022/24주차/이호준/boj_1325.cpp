/*******************************************************************
1325 효율적인 해킹
2022/10/27 이호준
# 아이디어
1. DFS
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define MAX 100000
int n, m;
vector<int> graph[MAX];
bool visited[MAX];
int cnt;
int nowMax;
vector<int> ans;

void reset() {
	for (int i = 1; i <= n; i++){
		visited[i] = false;
	}
}

void dfs(int v) {
	visited[v] = true;
	cnt++;
	for (auto w : graph[v]) {
		if (!visited[w]){
			dfs(w);
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int to, from;
		cin >>to >> from;
		graph[from].push_back(to);
	}

	for (int i = 1; i <= n; i++){
		cnt = 0;
		reset();
		dfs(i);

		if (cnt > nowMax){
			ans.clear();
			ans.push_back(i);
			nowMax = cnt;
		}
		else if (cnt == nowMax){
			ans.push_back(i);
		}
	}

	for (auto num : ans) {
		cout << num << " ";
	}
}