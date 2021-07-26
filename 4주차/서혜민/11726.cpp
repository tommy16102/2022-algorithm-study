#include <iostream>
using namespace std;

/*

2021.08.02 서혜민

n=1일 때, 1개
n=2일 때, 2개
n=3일 때, 3개
n=4일 때, 5개
...
이렇게 n일 때 만들 수 있는 방법은 방법의 수는 n-1과 n-2일 때 방법의 합과 같다.

*/

int arr[1001] = { 0, };
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3;i <= n;i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n] << endl;
}