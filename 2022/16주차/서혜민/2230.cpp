#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	if (M == 0) {
		cout << 0;
		return 0;
	}

	vector<long long> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];

	sort(V.begin(), V.end());

	long long ans = 2000000001;
	int l = 0;
	int r = 0;

	while (l < N && r < N) {
		if (V[r] - V[l] > M) {
			ans = min(ans, V[r] - V[l]);
			l++;
		}
		else if (V[r] - V[l] == M) {
			cout << M;
			return 0;
		}
		else {
			r++;
		}
	}

	cout << ans;
}
