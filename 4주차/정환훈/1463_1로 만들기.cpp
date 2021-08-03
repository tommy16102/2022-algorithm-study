#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*

    푼 날짜 : 2021/07/27
    기본 아이디어 : DP
    X가 3으로 나누어 떨어지면, 3으로 나눈다.
    X가 2로 나누어 떨어지면, 2로 나눈다.
    1을 뺀다.
	
*/


int main() {


	int x;
	cin >> x;

	int* memo = new int[1000001];

	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;
	memo[4] = 2;
	memo[5] = 3;
	memo[6] = 2;
	memo[7] = 3;
	memo[8] = 3;
	memo[9] = 2;


	for (int i = 10; i <= x; i++) {

		if (i % 2 == 0 && i % 3 == 0) {
			memo[i] = min(memo[i / 2], memo[i / 3]) + 1;
		}
		else if (i % 2 == 0) {
			memo[i] = min(memo[i / 2], memo[i - 1]) + 1;
		}
		else if (i % 3 == 0) {
			memo[i] = min(memo[i / 3], memo[i - 1]) + 1;
		}
		else {
			memo[i] = memo[i - 1] + 1;
		}
	}

	cout << memo[x];

	return 0;
}