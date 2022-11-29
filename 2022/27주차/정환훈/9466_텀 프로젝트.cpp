#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int sel[101010];
bool v[101010];
bool done[101010];
int go = 0;
void input() {
	go = 0;
	cin >> n;
	for (int i = 0; i < 101010; i++) {
		v[i] = false;
		done[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> sel[i];
	}
}

void dfs(int node) {
	v[node] = true;
	int next = sel[node];

	if (!v[next]) {
		dfs(next);
	}
	else if (!done[next]) {
		for (int i = next; i != node; i = sel[i]) {
			go++;
		}
		go++;
	}
	done[node] = true;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		if(!v[i])
			dfs(i);
	}
	cout << n - go << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}
	return 0;
}
