#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

/*

2021.01.15 서혜민

DP를 통해 N에서부터 1까지 도달하는 최단 경로를 answer배열에 저장을 한 뒤,
DFS를 통해 N부터 1까지의 최단 경로를 찾아 출력한다.

*/

int answer[1000001];

void dfs(int num, int count, vector<int> &v) {
	if (num == 1 && count == answer[1]) {
		for (auto& num : v) cout << num << ' ';
		cout << '\n';
		exit(0);
	}
	if (num<1 || count>answer[1]) return;
	if (num % 3 == 0 && answer[num / 3] == count + 1) {
		v.push_back(num / 3);
		dfs(num / 3, count + 1, v);
		v.pop_back();
	}
	if (num % 2 == 0 && answer[num / 2] == count + 1) {
		v.push_back(num / 2);
		dfs(num / 2, count + 1, v);
		v.pop_back();
	}
	if (answer[num - 1] == count + 1) {
		v.push_back(num - 1);
		dfs(num - 1, count + 1, v);
		v.pop_back();
	}
}

int main() {
	int N;
	cin >> N;

	memset(answer, 1000001, sizeof(answer));

	answer[N] = 0;
	for (int i = N;i >=1;i--) {
		if (i % 3 == 0) answer[i / 3] = min(answer[i / 3], answer[i] + 1);
		if (i % 2 == 0) answer[i / 2] = min(answer[i / 2], answer[i] + 1);
		answer[i - 1] = min(answer[i - 1], answer[i] + 1);
	}

	vector<int> v;
	v.push_back(N);
	cout << answer[1] << '\n';
	dfs(N, 0, v);
}
