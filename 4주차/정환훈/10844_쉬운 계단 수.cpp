#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

    푼 날짜 : 2021/07/30
    기본 아이디어 : DP 
    d[10][3] = digit 수가 10인데 3으로 끝나는 수
    로 j가 0, 1~8, 9로 case 나눠서 점화식

	
*/

int main() {


	int n;
	cin >> n;

	long long** d = new long long* [101];
	for (int i = 0; i < 101; i++) {
		d[i] = new long long[10];
	}

	//long long [10][3] digit 수가 10인데 3으로 끝나는 수


	d[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}


	// d[i+1][j] = d[i][j-1] + d[i][j+1] ( j : 1~8)

	for (int i = 2; i < 101; i++) {


		d[i][0] = (d[i - 1][1]) % 1000000000;

		for (int j = 1; j <= 8; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}

		d[i][9] = (d[i - 1][8]) % 1000000000;

	}

	long long* memo = new long long[101];

	for (int i = 1; i < 101; i++) {
		memo[i] = 0;
		for (int j = 0; j < 10; j++) {
			memo[i] += (d[i][j]) % 1000000000;
		}

		memo[i] %= 1000000000;
	}

	cout << memo[n];

	return 0;
}
