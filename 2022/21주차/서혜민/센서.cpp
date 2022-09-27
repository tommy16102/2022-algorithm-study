#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	if (K >= N) {
		cout << 0;
		return 0;
	}

	set<int> S;
	for (int i = 0; i < N; i++) {
		int J;
		cin >> J;
		S.insert(J);
	}

	vector<int> V, V2;
	for (int s : S) V.push_back(s);
	for (int i = 0; i < S.size() - 1; i++) {
		V[i] = V[i + 1] - V[i];
		V2.push_back(V[i]);
	}
	sort(V2.begin(), V2.end());

	int ans = 0;
	for (int i = 0; i < V2.size() - (K - 1); i++) ans += V2[i];
	cout << ans;
}