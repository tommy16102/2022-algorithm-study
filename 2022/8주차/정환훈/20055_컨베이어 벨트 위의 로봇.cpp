#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int n;
int k;


typedef struct block{
	int hp;
	bool robot;
} block;

deque<block> belt;


void input() {
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++) {
		int h;
		cin >> h;
		block b;
		b.robot = false;
		b.hp = h;
		belt.push_back(b);
	}
}

bool end() {
	int died = 0;
	for (int i = 0; i < belt.size(); i++) {
		if (belt[i].hp == 0)
			died++;
	}

	return k <= died;
}

void solve() {
	int t = 0;
	while (!end()) {
		t++;
		belt.push_front(belt.back());
		belt.pop_back();
		if (belt[n - 1].robot) // n번쨰 위치 도착 시 로봇 내림
			belt[n - 1].robot = false;

		for (int i = n - 2; i >= 0; i--) { // 뒤에부터 한 칸씩 이동
			if (belt[i].robot && !belt[i + 1].robot && belt[i + 1].hp >= 1) { // 현재 칸 로봇 있고 다음 칸 로봇 없고 다음 칸 체력 있으면
				belt[i + 1].hp--; // 체력 닳고
				belt[i].robot = false; // 로봇 이동
				if (i != n - 2)
					belt[i + 1].robot = true; // 로봇 도착
			}
		}

		if (belt[0].hp >= 1 && !belt[0].robot) { // 새 로봇 올림
			belt[0].robot = true;
			belt[0].hp--;
		}

		/*
			벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
			가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
			로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
			올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
			내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.		
		*/

	}
	cout << t;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}