#include <bits/stdc++.h>
using namespace std;
int n;
int s;
vector<int> seq;
void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		seq.push_back(t);
	}
}


void solve() {
	int start = 0; int end = 0;
	int sum = 0; int result = 0;
	int len = 100001;
	int nowLen = 0;

	// start, end 가 0에서 출발하여,
	// 현재 부분값이 s보다 큰 경우, 작은 경우, 같은 경우로 나눈다.
	// 부분값이 s보다 큰 경우는 start를 한 칸 뒤로 옮겨 부분값을 변동시킨다.
	// 부분값이 s보다 작은 경우는 end를 한 칸 뒤로 옮겨 부분값을 변동시킨다.
	// 본 문제에서는 s보다 큰 경우에서 가장 짧은 문자열 길이를 구하여야 하므로
	// end를 이동할 때 최소 문자열 길이를 체크해준다.

	while (1) {
		if (sum >= s) {
			len = min(len, nowLen);
			nowLen--;
			sum -= seq[start++];
		}
		else if (end == n) {
			if (len == 100001) {
				cout << 0;
			}
			else
				cout << len;
			return;
		}
		else {
			nowLen++;
			sum += seq[end++];
		}

	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}