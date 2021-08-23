#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*

2021.09.03

가장 최상위에 절대값이 가장 작은 수가 올 수 있도록 하기위해, 
양수가 들어가는 priority_queue는 내림차순으로, 음수는 오름차순으로 정렬이 될 수 있도록한다.
0이외의 수가 입력될 때는 해당하는 수에 맞춰서 양수나 음수 pq에 들어가게 된뒤,
0을 입력받으면 두 pq가 모두 비어있을 때는 0, 하나만 비어있을 때는 그 이외의 큐의 최상위 수,
둘 다 비어있지 않다면 두 큐의 최상위에 있는 수를 비교하여 절대값이 작은 수, 만약 절대값이 같다면
더 작은 수를 출력한다.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> plus;
	priority_queue<int> minus;

	int x;
	while (N--) {
		cin >> x;
		if (x < 0)minus.push(x);
		else if (x > 0)plus.push(x);
		else {
			if (plus.empty() && minus.empty()) cout << 0 << endl;
			else if (plus.empty()) {
				cout << minus.top() << endl;
				minus.pop();
			}
			else if (minus.empty()) {
				cout << plus.top() << endl;
				plus.pop();
			}
			else {
				int p = plus.top();
				int m = minus.top();
				if (abs(p) >= abs(m)) {
					cout << m << endl;
					minus.pop();
				}
				else {
					cout << p << endl;
					plus.pop();
				}
			}
		}
	}
}
