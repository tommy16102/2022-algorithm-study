#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> meeting;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start;
		int end;
		cin >> start >> end;
		meeting.push_back({ start,end });
	}
}

void solve() {
	// 시작 시간 기준으로 정렬
	sort(meeting.begin(), meeting.end());

	int i = 0;
	int ans = 0;
	// 전체 회의 수 살펴볼건데
	while (i < n) {
		
		ans++;
		if (meeting[i].first == meeting[i].second) { i++; continue; } // 반례(무한루프됨) : 시작시간 == 끝나는시간 넘기고 진행
		int now_end = meeting[i].second;
		// 끝 시간을 기준으로 해서
		while (i < n && now_end > meeting[i].first) { // 현재 회의 사이의 회의 살펴 보기
			if (now_end > meeting[i].second) { // 더 일찍 끝나는 회의 있으면 업데이트
				now_end = meeting[i].second;
			}
			i++;
		}
		// 결국 가장 일찍 끝나는 회의 하나 선택하고 계속 진행
	}
	cout << ans;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}