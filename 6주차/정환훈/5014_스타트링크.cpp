#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    푼 날짜 : 2021/08/13
    아이디어 : 그리디
*/


int total; // F : 토탈 층 개수
int now; // S : 현재 위치
int goal; // G : 목적지
int up; // U : 올라가는 칸수
int down; // D : 내려가는 칸수;


void input() {
	cin >> total >> now >> goal >> up >> down;
}

void solve() {
	for (int i = 0; i < 1000000; i++) {
		if (now == goal) {
			cout << i;
			return;
		}
		if (now + up > total && now - down < 1) // 이도저도 못하는 상황 (못 감)
			break;

		if (now < goal && now + up <= total) { // 일단 최소 goal 이상까지 올라가 보고
			now += up;
		}
		else if (now > goal || now - down > 0) { // 내려올 수 있으면 내려온다
			now -= down;
		}
	}
	cout << "use the stairs";
}

int main() {

	input();
	solve();

	return 0;
}
