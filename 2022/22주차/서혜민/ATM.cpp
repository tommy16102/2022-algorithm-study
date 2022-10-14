#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];

	sort(V.begin(), V.end());

	int ans = 0;
	int part = 0;
	for (int i = 0; i < V.size(); i++) {
		part += V[i];
		ans += part;
	}
	cout << ans;
}
