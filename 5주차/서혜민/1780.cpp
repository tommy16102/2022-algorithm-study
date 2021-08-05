#include <iostream>
using namespace std;

/*

2021.08.09 서혜민

가장 먼저 입력받은 종이의 모든 수를 확인해 모두 같은 수로 되어있다면 거기서 바로 그 수의 개수를 출력하여 끝내지만,
그렇지 않을 경우, 9개의 종이로 자르기 위해 길이의 3분의 1을 하나씩 더한 수가 각 종이의 왼쪽 위의 좌표가 되므로
이 좌표와 길이의 3분의 1을 매개변수로 재귀를 통해 새롭게 만든 사각형 내부에서 다시 숫자를 파악해서 모두 다 같은 수면
그 수의 개수를 늘려주고 그렇지 않으면 다시 재귀를 호출하는 방식을 진행한다.

*/

int arr[2188][2188] = { 0, };
int count[3] = { 0, };

void find(int i, int j, int len) {
	int a =0, b = 0, c = 0;
	for (int y = i;y < i + len;y++) {
		for (int x = j;x < j + len;x++) {
			if (arr[y][x] == 0) a++;
			if (arr[y][x] == 1) b++;
			if (arr[y][x] == -1) c++;
		}
	}
	if (a == (len * len)) {
		::count[0]++; 
	}
	else if (b == (len * len)) {
		::count[1]++;
	}
	else if (c == (len * len)) {
		::count[2]++;
	}
	else {
		for (int y = 1;y <= 3;y++) {
			for (int x = 1;x <= 3;x++) {
				find(i + (len / 3) * (y - 1), j + (len / 3) * (x - 1), (len / 3));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> arr[i][j];
		}
	}
	int a = 0, b = 0, c = 0; //0 1 -1 개수
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (arr[i][j] == 0) a++;
			if (arr[i][j] == 1) b++;
			if (arr[i][j] == -1) c++;
		}
	}
	if (a == N * N) {
		::count[0] = 1; ::count[1] = 0; ::count[2] = 0;
	}
	else if (b == N * N) {
		::count[0] = 0; ::count[1] = 1; ::count[2] = 0;
	}
	else if (c == N * N) {
		::count[0] = 0; ::count[1] = 0; ::count[2] = 1;
	}
	else {
		for (int i = 1;i <= 3;i++) {
			for (int j = 1;j <= 3;j++) {
				find(1 + (N / 3) * (i - 1), 1 + (N / 3) * (j - 1), (N / 3));
			}
		}
	}
	cout << ::count[2] << '\n' << ::count[0] << '\n' << ::count[1] << endl;
}