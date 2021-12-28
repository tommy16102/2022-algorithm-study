#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
    푼 날짜 : 2021/08/07
    아이디어 : 검사해봐서 안되면 9등분으로 자름 되면 -1, 0, 1 나눠서 덧셈

*/
int** map;
int answer[3] = { 0,0,0 };

bool test(int x, int y, int size) { // 해당 종이가 모두 같은 숫자로 이뤄져있는지 판단하는함수

	int t = map[x][y]; // 시작점 : [x][y]

	for (int i = x; i < x + size; i++) { // 가로 범위 : x ~ x + size
		for (int j = y; j < y + size; j++) { // 세로 범위 : y ~ y + size
			if (map[i][j] != t)
				return false;
		}
	}
	return true;
}

void cut(int x, int y, int size) { // 종이 9분할 하는 함수

	if (!test(x, y, size)) { // 조건에 맞지 않으면

		for (int i = 0; i < 3; i++) { // 가로 3등분
			for (int j = 0; j < 3; j++) { // 세로 3등분
				cut(x + (size / 3) * i, y + (size / 3) * j, size / 3); // size는 /3해서 넘겨준다
			}
		}

	}
	else { // 시험 통과 = 모두 다 같은 숫자
		// memo something...
		switch (map[x][y]) { 
		case -1:
			answer[0]++;
			break;
		case 0:
			answer[1]++;
			break;
		case 1:
			answer[2]++;
		default:
			break;
		}
	}



}

int main() {

	int n; cin >> n;

	map = new int*[n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}


	cut(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}



