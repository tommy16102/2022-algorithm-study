#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210831

int n;
vector<int> heights; // 높이
vector<int> dest; // 수신받은 아이들 목록

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	dest.push_back(0);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		heights.push_back(temp);
		dest.push_back(0);
	}
}

void solve() {
	stack<pair<int, int>> t; // 인덱스, 값

	// (4,4) (3,2) 
	for (int i = n - 1; i >= 0; i--) { // 6 3 5 2 4

		if (!t.empty() && t.top().second < heights[i]) { // 전파 받는 애 발견
			while (!t.empty() && t.top().second < heights[i]) {				
				dest[t.top().first + 1] = i + 1;// 현재 스택의 top에 있는 인덱스의 도착 인덱스 => i+1
				t.pop(); // 펑
			}
			t.push(make_pair(i, heights[i]));
		}
		else { // 없거나 받는 애 못 발견
			t.push(make_pair(i, heights[i]));
		}	
	}

	for (int i = 1; i < dest.size(); i++) {
		cout << dest[i] << " ";
	}

}

int main() {

	input();
	solve();

	return 0;
}