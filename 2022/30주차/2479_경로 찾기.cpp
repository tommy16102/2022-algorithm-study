#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, k, a, b;
string strs[3000];
map<string, bool> v;
vector<int> ans;
bool flag = false;
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> strs[i + 1];
	}
	cin >> a >> b;
}

void dfs(string str, vector<int> an) {
	v[str] = true;
	if(flag) return;
	if (str == strs[b]) {
		flag = true;
		ans = an;
		return;
	}
	for (int i = 1; i <= n; i++) {
		int no = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] != strs[i][j]) no++;
		}
		if (no == 1 && !v[strs[i]]) {
			an.push_back(i);
			dfs(strs[i], an);
			an.pop_back();
		}
	}
	v[str] = false;
}

void solve() {
	vector<int> temp;
	dfs(strs[a], temp);
	if (flag) {
		cout << a << " ";
		for (auto k : ans) {
			cout << k << " ";
		}
	}
	else {
		cout << -1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	
	return 0;
}
