#include <iostream>
#define DIV 1000000000
using namespace std;

/*

2021.08.02 서혜민

입력받은 n까지 1부터 9까지 가능한 1을 기준으로 자릿수가 하나씩 늘어날 때
마지막 자리에 9가 오게 하려면 그 전 수가 무조건 8이어야하고,
0이 오게하려면 이전의 수는 무조건 1이어야한다.
나머지 수들은 그 전의 수보다 1만 차이가 나게 해주면 된다.

이후, 계산한 0부터 9로 끝나는 모든 수들을 더해주면 된다.

*/

int arr[101][10] = { 0, };
int main() {
	int n;
	cin >> n;

	//n은 1일 때, 1~9 가능.
	for (int i = 1;i <= 9;i++) {
		arr[1][i] = 1;
	}

	for (int i = 2;i <= 100;i++) {
		for (int j =9 ;j >= 0;j--) {
			if (j == 9) arr[i][j] = arr[i - 1][8];
			else if (j == 0) arr[i][j] = arr[i - 1][1];
			else arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % DIV;
		}
	}
	int sum = 0;
	for (int i = 0;i <= 9;i++) {
		sum = (sum + arr[n][i]) % DIV;
	}
	cout << sum << endl;
}