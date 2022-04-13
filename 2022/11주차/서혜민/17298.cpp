#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n + 1), ans(n + 1, -1);
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	
	stack<int> s;
	for (int i = 1;i <= n;i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1;i <= n;i++) {
		cout << ans[i] << " ";
	}
}