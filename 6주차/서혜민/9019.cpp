#include <iostream>
#include <queue>
#include <string>
#include <limits.h>
#include <string.h>
using namespace std;

/*

2021.08.16 서혜민

입력받은 A와 아직 없는 경로인 빈 문자열 큐에 넣어준 뒤,
bfs로 D,S,L,R을 실행하면서 이전에 나오지 않은 숫자라면 queue에 해당 숫자와 경로를 저장.

*/

bool checked[10000] = { 0, };
queue<pair<int, string>> que;
int funcD(int n) {
	return n * 2 % 10000;
}

int funcS(int n) {
	if (n == 0) return 9999;
	return n - 1;
}

int funcL(int n) {
	return n%1000*10+n/1000;
}

int funcR(int n) {
	return n % 10 * 1000 + n / 10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int min = INT_MAX;
		int A, B;
		string ans;
		cin >> A >> B;

		que.push({ A,"" });
		checked[A] = 1;
		while (!que.empty()) {
			int toB = que.front().first;
			string route = que.front().second;
			que.pop();
			if (toB == B) {
				if (route.length() < min) {
					min = route.length();
					ans = route;
				}
				break;
			}
			if (!checked[(funcD(toB))]) {
				checked[(funcD(toB))] = 1;
				que.push({ funcD(toB),route + "D" });
			}
			if (!checked[(funcS(toB))]) {
				checked[(funcS(toB))] = 1;
				que.push({ funcS(toB),route + "S" });
			}
			if (!checked[(funcL(toB))]) {
				checked[(funcL(toB))] = 1;
				que.push({ funcL(toB),route + "L" });
			}
			if (!checked[(funcR(toB))]) {
				checked[(funcR(toB))] = 1;
				que.push({ funcR(toB),route + "R" });
			}
			memset(checked, 0, sizeof(checked));
		}
		while (!que.empty()) que.pop();
		cout << ans << endl;
	}
}
