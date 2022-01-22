#include <iostream>
using namespace std;

/*

2022.1.22

입력받은 수들에 대한 누적 합을 sumArr에 저장한다.
이후 입력받은 구간의 합을 구하기 위해 중복되는 부분은 빼주고,
필요한 부분은 더해주면서 합을 구한다.

*/

int sumArr[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0;i < 1025;i++) {
		sumArr[i][0] = 0;
		sumArr[0][i] = 0;
	}

	int input;
	for (int i = 1;i <= N;i++) {
		int sum = 0, rowSum = 0;
		for (int j = 1;j <= N;j++) {
			cin >> input;
			rowSum += input;
			sumArr[i][j] = rowSum;
			sumArr[i][j] += sumArr[i-1][j];
		}
	}

	while (M--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sumArr[x2][y2] - sumArr[x1 - 1][y2] - sumArr[x2][y1 - 1] + sumArr[x1-1][y1-1]<<'\n';
	}
}
