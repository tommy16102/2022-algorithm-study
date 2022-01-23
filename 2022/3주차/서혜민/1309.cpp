#include <iostream>
using namespace std;

/*

2022.1.23 

점화식: zoo[i] = zoo[i-1]*2 + zoo[i-2]
*/

int zoo[1000001];

int main() {
	int N;
	cin >> N;

	zoo[1] = 3;
	zoo[2] = 7;
	
	for (int i = 3;i <= N;i++) {
		zoo[i] = zoo[i - 1] * 2 + zoo[i - 2];
		zoo[i] %= 9901;
	}
	cout << zoo[N] << '\n';
}
