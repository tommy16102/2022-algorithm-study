#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
int ary[1001];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		int s;
		cin >> d >> s;
		pair<int, int> p = { s,d };
		pq.push(p);
	}
}

void solve() {



	// 가장 점수가 큰 순서대로 늘어놓은 후,
	// 해당 과제를 마감 전날 해결한다.
	// 만약 마감 전날 해야 할 과제가 있다면,
	// 그 전날로 해당 과제를 앞당긴 후, 원래 그 날 자리해 있는 과제와 점수를 비교한다.

	int answer = 0;
	while (!pq.empty()) {
		pair<int, int> t = pq.top();
		int day = t.second;
		if (ary[day] == 0) { // 그날 할거 없음
			ary[day] = t.first;
		}
		else{
			while (day > 0 && ary[day] >= t.first) { // 그날 할거 있고 해당 과제보다 점수를 더 많이줌
				day--;
			}
			ary[day] =  t.first;
		}
		pq.pop();
	}

	for (int i = 1; i <= 1000; i++) {
		answer += ary[i];
	}
	cout << answer;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();

	return 0;
}	