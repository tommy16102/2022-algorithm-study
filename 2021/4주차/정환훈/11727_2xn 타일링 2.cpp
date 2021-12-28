#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*

    푼 날짜 : 2021/07/28
    기본 아이디어 : DP 점화식

	
*/

int main() {

	// 2×n 크기의 직사각형을 1×2, 2×1, 2 x 2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
	// 가로 n 세로 2

	int n;
	int* memo = new int[1001];

	cin >> n;
	memo[1] = 1;
	memo[2] = 3;
	memo[3] = 5; // f(2) + f(1) + f(1)
	memo[4] = 11; // f(3) + f(2) + f(2)

	for (int i = 5; i <= n; i++) {
		memo[i] = (memo[i - 2] * 2 + memo[i - 1]) % 10007;
	}


	cout << memo[n];

	return 0;
}