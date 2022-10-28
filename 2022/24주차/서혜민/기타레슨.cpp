#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<long long> V(N);

	long long L = 0, R = 0;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
		R += V[i];
		L = max(L, V[i]);
	}

	while (L <= R) {
		long long mid = (L + R) / 2;
		long long sum = 0;
		long long cnt = 0;
		for (int i = 0; i < N; i++) {
			if (sum + V[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += V[i];
		}
		if (sum > 0) cnt++;

		if (cnt <= M) R = mid - 1;
		else L = mid + 1;
	}

	cout << L;
}
