#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
vector<int> sorted;
vector<int> transformed;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		x.push_back(t);
		transformed.push_back(-1);
	}
}


void solve() { 
	sorted = x;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	
	for (int i = 0; i < transformed.size(); i++) {
		cout << lower_bound(sorted.begin(), sorted.end(), x[i]) - sorted.begin() << ' ';
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}