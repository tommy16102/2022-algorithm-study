#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210826
int n;
priority_queue<int, vector<int>, greater<int>> plus_q; // 양수는 작은 순서대로 (절댓값 작음)
priority_queue<int> minus_q; // 음수는 큰 순서대로 (절댓값 작음)
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
}

void solve() {
	for (int i = 0; i < n; i++) {
		int temp; // 입력 value
		cin >> temp;

		if (temp > 0) { // 양수 최소 힙
			plus_q.push(temp);
		}
		else if (temp < 0) { // 음수 최대 힙
			minus_q.push(temp);
		}

		else { // 0 들어왔을 때, pop

			int p1 = 0;
			int p2 = 0;


			if (plus_q.empty() && minus_q.empty()) { // 4가지 경우 분기 처리
				cout << 0 << endl;
 			}

			else if (!plus_q.empty() && !minus_q.empty()) {
				int t1 = plus_q.top();
				int t2 = minus_q.top();

				if (t1 >= abs(t2)) {
					cout << t2 << endl;
					minus_q.pop();
				}
				else {
					cout << t1 << endl;
					plus_q.pop();
				}
			}

			else if (!plus_q.empty() && minus_q.empty()) {
				cout << plus_q.top() << endl;
				plus_q.pop();
			}

			else if (plus_q.empty() && !minus_q.empty()) {
				cout << minus_q.top() << endl;
				minus_q.pop();
			}

		}
	}

}

int main() {

	input();
	solve();
	return 0;
}