#include <iostream>
using namespace std;

/*

2021.08.02 서혜민

n이 1일 때는 1,
n이 2일 때는 3,
n이 3일 때는 5,
n이 4일 때는 11,
n이 5일 때는 21,
...

f(n) = 2*f(n-2)+f(1)이라는 점화식이 완성된다.

*/

long long int arr[1001] = { 0, };
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3;i <= n;i++) {
		arr[i] = arr[i - 1] % 10007 + (arr[i - 2] * 2) % 10007;
	}
	cout << arr[n] % 10007 << endl;
}