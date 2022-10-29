#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	double n;
	cin >> n;

	vector<double> V(n);
	for (int i = 0; i < n; i++) cin >> V[i];

	double ans = 0;
	for (int i = 0; i < n; i++) {
		double cnt = 0;
		double h = -9999999999;
		for (int j = i + 1; j < n; j++) {
			if (V[i] + (h * (j - i)) < V[j]) {
				cnt++;
				h = (V[j] - V[i]) / (j - i);
			}
		}
		h = -9999999999;
		for (int j = i - 1; j >= 0; j--) {
			if (V[i] + (h * (i - j)) < V[j]) {
				cnt++;
				h = (V[j] - V[i]) / (i - j);
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}
