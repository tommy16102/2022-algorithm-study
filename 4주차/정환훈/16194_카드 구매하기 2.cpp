#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*

    푼 날짜 : 2021/07/29
    기본 아이디어 : 1과 똑같은데 이제 DP로 푼 그리고 min으로 바꾼

*/

int main() {

	int n;

	cin >> n;

	int* memo = new int[n + 1];
	

	for (int i = 1; i <= n; i++) {
		cin >> memo[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			memo[i] = min(memo[i], memo[i - j] + memo[j]);
		}
	}
	cout << memo[n];
	return 0;
}