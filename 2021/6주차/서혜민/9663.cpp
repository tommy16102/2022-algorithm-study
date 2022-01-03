#include <iostream>
#include <cstdlib>
using namespace std;

/*

2021.08.14 서혜민

퀸은 상하좌우 대각선을 길이 제한없이 갈 수 있으므로, 체스판의 세로줄에 하나밖에 올 수 없다.
가장 왼쪽의 세로줄부터 시작하여, for문을 통해서 가로줄에 위치하게 한 뒤, check함수를 통해서
가로줄에 위치하게 했을 때 같은 상하좌우 선에 없거나 이전에 놓았던 퀸과 대각선 자리에 없으면
다음 세로줄에 퀸을 놓는다.

*/

int chess[16];
int count = 0;

int N;

bool check(int sero) {
	for (int i = 1;i < sero;i++) {
		if (chess[i] == chess[sero] || (sero - i) == abs(chess[sero] - chess[i])) {
			return false;
		}
	}
	return 1;
}

void putQueen(int sero) {
	if (sero == N+1) {
		::count++;
		return;
	}
	for (int i = 1;i <= N;i++) {
		chess[sero] = i;
		if (check(sero)) putQueen(sero + 1);
	}
}

int main() {
	cin >> N;
	putQueen(1);
	cout << ::count << endl;
}
