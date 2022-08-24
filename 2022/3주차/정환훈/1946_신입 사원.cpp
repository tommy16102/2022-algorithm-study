#include <bits/stdc++.h>
using namespace std;

int n;
int N;
vector<pair<int, int>> emps;
void input() {
	cin >> N;
	emps.clear();
	for (int i = 0; i < N; i++) {
		int t1; int t2;
		cin >> t1 >> t2;
		emps.push_back({ t1,t2 });
	}
}


void solve() { 
	int answer = emps.size();
	sort(emps.begin(), emps.end());
	int least = emps[0].second;

	for (int i = 0; i < emps.size(); i++) {

		if (emps[i].second < least) {
			least = emps[i].second;
		}
		else {
			answer--;
		}
		/*
		* 1 4 o
		* 2 5 x
		* 3 6 x
		* 4 2 o -> 2로
		* 5 7 x
		* 6 1 o -> 1로
		* 7 3 ㅌ
		* 
			43 6
			7 3
			4 2
			1 4
			5 7
			2 5
			6 1
		*/
		// 1 100
		// 5 3
		// 6 22
		// 8 53
		// 42 2
		// 65 1
	}
	cout << 1 + answer << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		input();
		solve();
	}
}