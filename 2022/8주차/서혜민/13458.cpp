#include <iostream>
#include <vector>
using namespace std;

/*

2022.3.17

시험장별로 응시자수에서 총감독관 1명이 감시할 수 있는 응시자를 빼준 다음
해당 응시자 수에서 부감독관이 감시할 수 있는 응시자를 나눠서 필요한 인원 수를 구한다.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0;i < N;i++) cin >> v[i];

	int B, C;
	cin >> B >> C;

	long long ans = 0;

	for (int i = 0;i < N;i++) {
		v[i] -= B;
		ans++;

		if (v[i] <= 0) continue;

		ans += (v[i] / C);
		if (v[i] % C != 0) ans++;
	}

	cout << ans;
}