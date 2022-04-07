#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> V(N);
	for (int i = 0;i < N;i++) cin >> V[i];

	int p1 = 0, p2 = 0;
	long long sum = V[p1];
	int len = N + 1;

	while (p1 < N && p2 < N) {
		if (sum >= S) {
			len = min(len, p2 - p1 + 1);

			sum -= V[p1++];
			if (p1 > p2) {
				p2 = p1;
				sum = V[p1];
			}
		}
		else  sum += V[++p2];
	}

	if (len == N + 1) len = 0;

	cout << len;
}
