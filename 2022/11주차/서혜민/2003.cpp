#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> V(N);
	for (int i = 0;i < N;i++) cin >> V[i];

	int p1 = 0;
	int p2 = 0;
	int sum = V[0];
	int cnt = 0;

	while (p1 < N && p2 < N) {
		if (sum < M) sum += V[++p2];
		else if (sum > M) {
			sum -= V[p1++];
			if (p1 > p2) {
				p2 = p1;
				sum = V[p2];
			}
		}
		if (sum == M) {
			sum += V[++p2];
			cnt++;
		}
	}

	cout << cnt;
}