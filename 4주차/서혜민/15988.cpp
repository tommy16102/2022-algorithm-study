#include <iostream>
using namespace std;

/*

2021.08.02 서혜민

n=1 -> 1
n=2 -> 2
n=3 -> 4
n=4 -> 7
n=5 -> 13
...

f(n)=f(n-1)+f(n-2)+f(n-3)
1000000009 나눈 값을 더한 뒤, 1000000009로 다시 한번 나눠준 값을 저장.

*/

long long int arr[1000001] = { 0, };
int main() {
	int T;
	cin >> T;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4;i < 1000001;i++) {
		arr[i] = (arr[i - 1]% 1000000009 + arr[i - 2] % 1000000009 + arr[i - 3] % 1000000009) % 1000000009;
	}
	int n;
	while (T--) {
		cin >> n;
		cout << arr[n] << endl;
	}
}