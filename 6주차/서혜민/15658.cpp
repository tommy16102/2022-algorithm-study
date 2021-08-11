#include <iostream>
#include <limits.h>
using namespace std;

/*

2021.08.11 서혜민

재귀를 통해 해당 + - * / 연산.

*/

int N;
int arr[11];
int plusCount, minusCount, multiCount, divCount;
int max = INT_MIN, min = INT_MAX;

void calc(int sum, int nextindex, int p, int m, int m2, int d) {
	if (nextindex == N) {
		if (sum > ::max) ::max = sum;
		if (sum < ::min) ::min = sum;
		return;
	}

	if (p < ::plusCount) {
		calc(sum + arr[nextindex], nextindex + 1, p + 1, m, m2, d);
	}
	if (m < ::minusCount) {
		calc(sum - arr[nextindex], nextindex + 1, p, m + 1, m2, d);
	}
	if (m2 < ::multiCount) {
		calc(sum * arr[nextindex], nextindex + 1, p, m, m2 + 1, d);
	}
	if (d < ::divCount) {
		calc(sum / arr[nextindex], nextindex + 1, p, m, m2, d + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < N;i++) cin >> arr[i];
	cin >> ::plusCount >> ::minusCount >> multiCount >> ::divCount;
	calc(arr[0], 1, 0, 0, 0, 0);

	cout << ::max << endl << ::min << endl;
}
