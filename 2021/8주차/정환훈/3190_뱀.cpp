#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std; // 210901

int n; // 보드의 크기
int k; // 사과의 개수
int map[101][101]; // 보드 현상태 0: 땅 1: 사과 2: 뱀
int l; // 명령의 개수
vector<pair<int, char>> cmd; // 시간, 회전 pair인 명령들
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 101; i++) { // 초기화
		for (int j = 0; j < 101; j++) {
			map[i][j] = 0;
		}
	}
	cin >> n >> k;
	for (int i = 0; i < k; i++) { //사과 받기
		int ax; int ay;
		cin >> ax >> ay;
		map[ax][ay] = 1; // 사과 = 1
	}
	cin >> l;
	for (int i = 0; i < l; i++) { // 명령 받기
		int	t;
		char turn;
		cin >> t >> turn;
		cmd.push_back(make_pair(t, turn));
	}
}

void solve() {

	map[1][1] = 2; // 뱀 = 2
	int time = 0;
	int h_id = 0; // 머리 방향 변할 때 몇번째 커맨드인지
	int t_id = 0; // 꼬리 ''
	int h_dir = 3; // 머리 방향 상하좌우 0123
	int t_dir = 3; // 꼬리 방향
	int h_x = 1; int h_y = 1; // 머리 좌표
	int t_x = 1; int t_y = 1; // 꼬리 좌표
	int size = 1; // 처음 사이즈 = 1
	while (1) {
		time++; // 시간 1초 증가
		int h_nx = h_x; // 머리 다음 x
		int h_ny = h_y; // 머리 다음 y
		int t_nx = t_x; // 꼬리 다음 x
		int t_ny = t_y; // 꼬리 다음 y

		if (cmd[h_id].first + 1 == time) { // 현재 시간이 명령 직후 시간이면
			switch (cmd[h_id].second) { // 머리 진행방향 바꾸기
			case 'D': // 우회전
				switch (h_dir) { // 0123 -> 상하좌우
				case 0: // 상
					h_dir = 3; // 우
					break;
				case 1: // 하
					h_dir = 2; // 좌
					break;
				case 2: // 좌
					h_dir = 0; // 상
					break;
				case 3: // 우
					h_dir = 1 ; // 하
					break;
				}

				break;
			case 'L': // 좌회전
				switch (h_dir) {
				case 0:
					h_dir = 2;
					break;
				case 1:
					h_dir = 3;
					break;
				case 2:
					h_dir = 1;
					break;
				case 3:
					h_dir = 0;
					break;
				}
				break;
			}

			h_id++; // 머리는 다음 명령 기다리기
		}
		if (cmd[t_id].first + size == time) { // 꼬리 방향 변할 때는 size 더해준 직후
			switch (cmd[t_id].second) { // 꼬리 방향 변환
			case 'D': // 우회전
				switch (t_dir) {
				case 0:
					t_dir = 3;
					break;
				case 1:
					t_dir = 2;
					break;
				case 2:
					t_dir = 0;
					break;
				case 3:
					t_dir = 1;
					break;
				}

				break;
			case 'L': // 좌회전
				switch (t_dir) {
				case 0:
					t_dir = 2;
					break;
				case 1:
					t_dir = 3;
					break;
				case 2:
					t_dir = 1;
					break;
				case 3:
					t_dir = 0;
					break;
				}
				break;
			}
			t_id++;
		}



		switch (h_dir) { // 머리 위치 이동해주는 로직
		case 0: // 상
			h_nx = --h_x;
			break;
		case 1: // 하
			h_nx = ++h_x;
			break;
		case 2: // 좌
			h_ny = --h_y;
			break;
		case 3: // 우
			h_ny = ++h_y;
			break;
		}

		switch (t_dir) {  // 꼬리 위치 이동
		case 0: // 상
			t_nx = t_x - 1;
			break;
		case 1: // 하
			t_nx = t_x + 1;
			break;
		case 2: // 좌
			t_ny = t_y - 1;
			break;
		case 3: // 우
			t_ny = t_y + 1;
			break;
		}


		//cout << "X : " << h_nx << " Y : " << h_ny << endl;

		if (h_nx <= 0 || h_ny <= 0 || h_nx > n || h_ny > n || map[h_nx][h_ny] == 2) { // 벽에 닿거나 자신의 몸 만남
			break;
		}
		else if (map[h_nx][h_ny] == 1) { // 사과 만날 시 꼬리는 그대로
			h_x = h_nx; // 머리 이동
			h_y = h_ny;
			map[t_x][t_y] = 2; // 꼬리도 뱀
			map[h_x][h_y] = 2; // 사과자리 뱀 머리
			//cout << "시간 " << time << "에서 사과 ! " << h_nx << " " << h_ny << endl;
			size++; // 커짐
		}
		else if (map[h_nx][h_ny] == 0) { // 그냥 평범한 땅 밟음 => 꼬리도 이동
			// 꼬리 dir 바뀔 때는 cmd time + size == time 될 때
			map[t_x][t_y] = 0; // 현재 꼬리는 이제 땅이 된다
			map[t_nx][t_ny] = 2; // 다음 꼬리 뱀
			map[h_nx][h_ny] = 2; // 다음 머리도 뱀
			t_x = t_nx; // 꼬리 이동
			t_y = t_ny;
			//cout << "시간 " << time << "에서 땅 ! " << h_nx << " " << h_ny << endl;
		}

	}

	cout << time;

}

int main() {

	input();
	solve();

	return 0;
}