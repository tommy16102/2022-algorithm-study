#include <bits/stdc++.h>
using namespace std;

int d[10000]; // 수열
int a; // 초기값
int p; // 자리값 p제곱
int check[10000000]; // 해당 수의 수열 index

void input() {
	cin >> a >> p;
}

void solve() {

	d[1] = a;
	check[a] = 1; // 초기값 설정

	int i = 2; // 수열 index
	int next = 0; // 수열의 다음 값

	while (1) {
		next = 0;
		int prev = d[i - 1]; // 수열의 이전 값 가져와서
		while (prev > 0) { // 각 자릿수 p제곱 계산하여 더하기
			int cur = 1;
			for (int j = 0; j < p; j++) {
				cur *= prev % 10;
			}
			next += cur;
			prev = prev / 10;
		}
		d[i] = next;
		if (check[next]) { // 해당 값이 이미 등장했다면 break
			break;
		}
		check[next] = i; // 첫 등장시 check에 index 기억한 후 진행
		i++;
	}
	cout << check[next] - 1; // 등장한 index - 1 = 남은 수열 개수
}

int main(void) {

	input();
	solve();
}