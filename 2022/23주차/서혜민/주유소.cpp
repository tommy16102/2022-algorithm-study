#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;

	vector<long long> road(N - 1);
	vector<long long> lit(N);

	for (int i = 0; i < N - 1; i++) cin >> road[i];
	for (int i = 0; i < N; i++) cin >> lit[i];

	long long ans = 0;
	long long prior = 1000000001;
	for (int i = 0; i < N - 1; i++) {
		if (lit[i] < prior) prior = lit[i];
		ans += prior * road[i];
	}

	cout << ans;
}
