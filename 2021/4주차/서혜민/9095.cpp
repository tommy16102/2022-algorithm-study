#include <iostream>
using namespace std;

/*

2021.08.02 ¼­Çı¹Î

n=1 -> 1
n=2 -> 2
n=3 -> 4
n=4 -> 7
n=5 -> 13
...

f(n)=f(n-1)+f(n-2)+f(n-3)

*/

int arr[12] = { 0, };
int main() {
	int T;
	cin >> T;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4;i < 11;i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	int n;
	while (T--) {
		cin >> n;
		cout << arr[n] << endl;
	}
}