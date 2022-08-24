#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> seq;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		seq.push_back(t);
	}
}

int oken[1000001];
void solve() {

	stack<pair<int,int>> st; // value,, index
	int i = 0;
	while (i < n) {
		
		if (st.empty()) { // 스택 비었음
			st.push({ seq[i],i });
			i++;
		}

		else if (st.top().first >= seq[i]) { // 스택 안에 있는 친구 성불
			st.push({ seq[i], i });
			i++;
		}
		else if (st.top().first < seq[i]) { // 스택에 push 하여 갱신할 값 바꿈
			oken[st.top().second] = seq[i];
			st.pop();
		}

	}

	while (!st.empty()) { // 남은 애들 -1로 채우기
		oken[st.top().second] = -1;
		st.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << oken[i] << " ";
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();


	return 0;
}