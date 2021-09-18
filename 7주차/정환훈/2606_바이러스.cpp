#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/18
    아이디어 : dfs
*/


int n;
int connect;
int answer = 0;
int graph[101][101];
bool virus[101] = { false };

void input() {
	cin >> n >> connect;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < connect; i++) {
		int from; int to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
}

vector<int> next(int st) { // 현재 vertex와 연결된 리스트 반환

	vector<int> result;

	for (int i = 0; i < 101; i++) {
		if (graph[i][st] == true) {
			result.push_back(i);
		}
	}

	return result;
}

void dfs(int start) {

	vector<int> next_go = next(start);
	if (next_go.empty()) {
		return;
	}
	for (int i = 0; i < next_go.size(); i++) {
		int candy = next_go[i];
		if (virus[candy] == false) {
			virus[candy] = true;
			answer++;
			dfs(candy);
		}
	}
}

void solve() {

	virus[1] = true;
	dfs(1);
	cout << answer;

}

int main() {
	input();
	solve();

	return 0;
}