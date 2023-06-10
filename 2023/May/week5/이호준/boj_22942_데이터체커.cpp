/*******************************************************************
Algorithm Study
Baekjoon 22942 데이터 체커
2023/06/04 이호준
# 아이디어
1. Stack 아이디어가 굉장히 좋다.
*******************************************************************/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

struct coord {
	int val, isOpen, idx;
};

bool cmp(coord a, coord b) { 
    return a.val < b.val; 
}
int N;
vector<coord> vc;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, r; cin >> x >> r;
		vc.push_back({ x - r, 0, i });
		vc.push_back({ x + r, 1, i });
	}
	sort(vc.begin(), vc.end(),cmp);
	bool flag = true;
	stack<int> stk;
	for (coord P : vc) {
		if (P.isOpen == 0)
			stk.push(P.idx);

		else{
			if (P.idx == stk.top())
				stk.pop();
			else { 
				flag = false; 
				break;
			}
		}
	}
	if (flag)
		cout << "YES";
	else cout << "NO";
	return 0;
}