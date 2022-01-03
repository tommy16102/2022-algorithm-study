#include <iostream>
using namespace std;

bool board[101][101];

/*
입력받은 두 좌표 내부에 포함된 직사각형 영역을 1로 설정
1인 영역의 합을 구하면 된다.
*/
int main() {
	
	int x1, y1, x2, y2;
	for (int i = 0;i < 4;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int y = y1;y < y2;y++) {
			for (int x = x1;x < x2;x++) {
				board[x][y] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0;i < 101;i++) {
		for (int j = 0;j < 101;j++) {
			if (board[i][j]) sum++;
		}
	}

	cout << sum << endl;
}