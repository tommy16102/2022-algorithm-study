#include <iostream>
#include <string>
using namespace std;

/*

2021.08.09 서혜민

늑대를 기준으로 bfs를 통해 양을 만나게 되면 울타리 -> 시간 초과.

모든 늑대를 울타리로 감싸줌.

*/

string arr[501];
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,1,0,-1 };

int main() {
	int R, C;
	cin >> R >> C;
	arr[0] = "";
	for (int i = 1;i <= R;i++) {
		string s;
		cin >> s;
		arr[i] = " " + s;
	}

	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			if (arr[i][j] == 'W') {
				for (int k = 0;k < 4;k++) {
					int x = i + moveX[k];
					int y = j + moveY[k];
					if (x >= 1 && y >= 1 && x <= R && y <= C) {
						if (arr[x][y] == 'S') {
							cout << 0 << endl;
							return 0;
						}
						else if (arr[x][y] == 'W') continue;
						else arr[x][y] = 'D';
					}
				}
			}
		}
	}
	cout << 1 << endl;
	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}
