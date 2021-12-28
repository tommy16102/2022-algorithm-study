#include <iostream>
#include <limits.h>
using namespace std;

/*

2021.08.11 서혜민

배열의 첫번째 원소를 시작으로 +,-,*,/ 연산자의 개수를 하나씩 줄여가면서 재귀를 통해
계산을 마지막 원소까지 한 뒤, max,min과 비교

*/

int N;
int arr[11];
int max = INT_MIN;
int min = INT_MAX;
int plusCount, minusCount, multiCount, divCount;

void calculate(int sum, int next_index, int p, int m, int m2, int d) {
	if (next_index == N) {
		if (sum > ::max) ::max = sum;
		if (sum < ::min) ::min = sum;
	}
	if (p < plusCount) {
		calculate(sum + arr[next_index], next_index + 1, p + 1, m, m2, d);
	}
	if (m < minusCount) {
		calculate(sum - arr[next_index], next_index + 1, p, m+1, m2, d);
	}
	if (m2 < multiCount) {
		calculate(sum * arr[next_index], next_index + 1, p, m, m2+1, d);
	}
	if (d < divCount) {
		calculate(sum / arr[next_index], next_index + 1, p, m, m2, d+1);
	}
}


int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	cin >> plusCount >> minusCount >> multiCount >> divCount;

	calculate(arr[0], 1, 0, 0, 0, 0);
	cout << ::max << endl << ::min << endl;
}
