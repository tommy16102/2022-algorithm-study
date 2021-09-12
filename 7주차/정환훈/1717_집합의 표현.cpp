#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    푼 날짜 : 2021/08/20
    아이디어 : 유니온 파인드? 이딴게 다 있네
*/

using namespace std;
int n; int m;
int parent[1000001];

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) { // 초기 부모값은 자기 자신을 쥐고 있는다
		parent[i] = i;
	}
}

int find_parent(int x) {// 최종 부모가 누군지 찾기

	if (parent[x] == x) {// 탈출 조건 : 대빵 찾기(집합에서 제일 작은 값)
		return x;
	}
	else {
		int p = find_parent(parent[x]); // 재귀적으로 자신의 부모->부모->부모... 찾는다
		parent[x] = p; // 현재 자신의 부모값 갱신
		return p;
	}
}

void merge(int x, int y){

	// 부모값 갱신할 건데, 큰 애들이 작은 애들에게 맞춰진다

	if (x <= y) {
		parent[y] = parent[x];
	}

	else {
		parent[x] = parent[y];
	}

}

void solve() {

	for (int i = 0; i < m; i++) {
		int op;		
		int x;		int y;
		cin >> op >> x >> y;
		int p_x = find_parent(x);
		int p_y = find_parent(y);


		if (op == 0) { // union
			if (p_x != p_y) { // 같은 집합이면 안해도 되니까
				merge(p_x, p_y);
			}
		}

		else if (op == 1) { // 같은 집합인가?
			if (p_x == p_y) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}

	}
}

int main() {

	input();
	solve();

	return 0;
}