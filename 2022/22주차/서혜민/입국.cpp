#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<long long> V(N);
	long long end = 0;
	for (int i = 0;i < N;i++) {
		cin >> V[i];
		end = max(end, V[i]);
	}

	long long ans = 1000000000000000000;
	long long start = 0;
	end *= M;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < V.size(); i++) sum += mid / V[i];
		if (sum >= M) {
			end = mid - 1;
			ans = min(ans, mid);
		}
		else start = mid + 1;
	}

	cout << ans;
		
}
