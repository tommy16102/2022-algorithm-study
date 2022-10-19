#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n, d, k, c;
int dish[3000001];
unordered_map<int, int> _map;
void input() {
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> dish[i];
	}
}

void solve() {
	int start = 0;
	int end = k - 1;
	int ans = 0;
	for (int i = start; i <= end; i++) {
		if (_map.find(dish[i]) == _map.end())
			_map.insert({ dish[i], 1 });
		else _map[dish[i]]++;
	}

	for (int i = 0; i < n; i++) {
		_map[dish[start]]--;
		if (_map[dish[start]] <= 0) {
			_map.erase(dish[start]);
		}
		start++;
		if (_map.find(dish[(end + 1) % n]) == _map.end()) {
			_map.insert({ dish[(end + 1) % n], 1 });
		}
		else {
			_map[dish[(end + 1) % n]]++;
		}
		end++;
		_map[c] = 1;
		ans = max(ans, (int)_map.size());
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	
	return 0;
}
