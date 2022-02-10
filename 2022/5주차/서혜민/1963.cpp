#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

/*

2022.2.10

BFS 방식으로 첫 번째 숫자부터 for문을 통해 하나의 자리수의 숫자를 바꿨을 때 소수인 수를 탐색해나간다.

*/

const int MAX = 9999;
bool isntPrime[MAX + 1];
bool visited[MAX + 1];

void checkPrime() {
	for (int i = 2;i <= MAX; i++) {
		if (isntPrime[i]) continue;
		for (int j = i * i; j <= MAX;j += i) isntPrime[j] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	checkPrime();

	while (T--) {
		string from, to;
		cin >> from >> to;

		queue<pair<string, int>> queue;
		visited[stoi(from)] = 1;
		queue.push({ from, 0 });
		
		bool canChange = false;
		while (!queue.empty()) {
			string num = queue.front().first;
			int cnt = queue.front().second;
			if (num == to) {
				cout << cnt << '\n';
				canChange = 1;
				break;
			}
			queue.pop();
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j <= 9;j++) {
					if (i == 3 && j == 0) continue;
					string change = num;
					change[i] = char(j + 48);
					if (change == num) continue;
					int changeNum = stoi(change);
					if (changeNum < 1000) continue;
					if (visited[changeNum] || isntPrime[changeNum]) continue;
					visited[changeNum] = 1;
					queue.push({ change, cnt + 1 });
				}
			}
		}
		if (!canChange) cout << "Impossible\n";

		memset(visited, 0, sizeof(visited));
	}
}