#include <iostream>
#define DIV 10007
using namespace std;

/*

2021.07.29 서혜민

arr[수의 길이][끝자리 수]

끝자리 수가 1이라면 이전 자리는 0또는 1이 가능하므로
해당 길이보다 1 작은 수에서 끝자리 수가 1 이하인 경우를 모두 더한 값이 된다.

*/

int arr[1001][10] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0;i <= 9;i++) arr[1][i] = 1;

	for (int i = 2;i <= N;i++) {
		for (int j = 0;j <= 9;j++) {
			int sum = 0;
			for (int k = 0;k <= j;k++) {
				sum = (sum + arr[i-1][k]) % DIV;
			}
			arr[i][j] = sum;
		}
	}
	int sum = 0;
	for (int i = 0;i <= 9;i++) sum = (sum + arr[N][i]) % DIV;
	cout << sum << endl;
}