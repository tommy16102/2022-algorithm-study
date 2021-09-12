#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
/*
    푼 날짜 : 2021/08/14
    아이디어 : BFS
*/

int t; // 케이스 총 개수
int from; int to;
vector<string> answers;
void input() {

	cin >> t;
}

int D(int n) { // D 연산 결과
	return (2 * n) % 10000;
}
int S(int n) { // S 연산 결과
	if (n == 0) return 9999;
	else return n - 1;
}
int L(int n) { // L 연산 결과

	int d1 = (n / 1000) % 10;
	int d2 = (n / 100) % 10;
	int d3 = (n / 10) % 10;
	int d4 = (n / 1) % 10;
	int result = d2 * 1000 + d3 * 100 + d4 * 10 + d1;

	return result;
}
int R(int n) { // R 연산 결과
	int d1 = (n / 1000) % 10;
	int d2 = (n / 100) % 10;
	int d3 = (n / 10) % 10;
	int d4 = (n / 1) % 10; // 1234 -> 4123
	int result = d4 * 1000 + d1 * 100 + d2 * 10 + d3;

	return result;
}

string bfs() {
	queue<pair<int, string>> q;
	string ex = "";
	q.push(make_pair(from, ex));
	bool visited[10000] = { false, }; // 해당 수를 방문?
	visited[q.front().first] = true;

	while (!q.empty()) {
		pair<int, string> now = q.front(); // 큐에서 하나 뽑아서
		ex = now.second;
		q.pop();
		int d = D(now.first); // 각각 DSLR 연산을 한 n을 얻는다
		int s = S(now.first);
		int l = L(now.first);
		int r = R(now.first);

		if (visited[d] == false) { // d에 아직 안 갔으면
			q.push(make_pair(d, ex + "D")); // 식에 D 추가 후 방문
			visited[d] = true;
			if (d == to) return ex + "D"; // to에 도달시 리턴
		}
		if (visited[s] == false) { // 이하 반복
			q.push(make_pair(s, ex + "S"));
			visited[s] = true;
			if (s == to) return ex + "S";
		}
		if (visited[l] == false) {
			q.push(make_pair(l, ex + "L"));
			visited[l] = true;
			if (l == to) return ex + "L";
		}
		if (visited[r] == false) {
			q.push(make_pair(r, ex + "R"));
			visited[r] = true;
			if (r == to) return ex + "R";

		}

	}
}

void solve() {

	for (int i = 0; i < t; i++) {
		cin >> from >> to;
		cout << bfs() << endl;
	}



}

int main() {

	input();
	solve();

	return 0;
}
