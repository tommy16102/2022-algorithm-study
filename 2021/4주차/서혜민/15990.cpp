#include <iostream>
using namespace std;

/*

2021.08.02 서혜민

같은 수는 연속으로 사용할 수 없기 때문에,
합이 n인 수를 만드는 방법의 수는
n-1에서 1이 아닌 2또는 3일 올 때 거기에 1을 붙여주는 경우
n-2에서 뒷자리가 1또는 3이 올 때 거기에 2를 붙여주는 경우
n-3에서 뒷자리가 1 또는 2가 올 때 거기에 3을 붙여주는 경우의 합과 같다.

*/

long long int arr[100001][4] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	arr[1][1] = 1;
	arr[2][2] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	arr[3][3] = 1;
	for (int i = 4;i <= 100000;i++) {
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3])%1000000009;
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % 1000000009;
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % 1000000009;
	}
	while (T--) {
		int n;
		cin >> n;
		cout <<((arr[n][1]+arr[n][2]) % 1000000009 +arr[n][3] ) % 1000000009 << endl;
	}
}