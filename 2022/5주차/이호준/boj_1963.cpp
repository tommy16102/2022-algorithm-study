/*******************************************************************
Algorithm Study
Baekjoon OJ BFS
1963 소수 경로
2022/02/14 이호준
# 아이디어
1. BFS를 하는 도중 소수를 체킹한다.
*******************************************************************/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool visited[10000];

bool isPrime(int x) {
	for (int i = 2; i <= x/2; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input, target;
		cin >> input >> target;

		// { number, try_count }
		queue<pair<int, int>> q;
		q.push({ input, 0 });
		visited[input] = true;
		while (!q.empty()) {
			int current_value = q.front().first;
			int current_count = q.front().second;
			q.pop();

			if (current_value == target) {
				cout << current_count << "\n";
				break;
			}

			string temp = to_string(current_value);

			for (int j = 0; j < 4; j++) {
				for (int b = 0; b < 10; b++) {
					if (j == 0 && b == 0)
						continue;
					char temp2 = temp[j];
					temp[j] = char(b+48);
					int next_value = stoi(temp);
					if (!visited[next_value]) {
						if (isPrime(next_value)) {
							visited[next_value] = true;
							q.push({ next_value, current_count+1 });
						}
					}
					temp[j] = temp2;
				}
			}
		}
		for (int a = 0; a <= 10000; a++) {
			visited[a] = false;
		}
	}

	return 0;
}