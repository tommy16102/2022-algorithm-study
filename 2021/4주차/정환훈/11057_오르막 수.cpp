#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

    푼 날짜 : 2021/07/30
    기본 아이디어 : DP 
    d[10][3] = digit 수가 10인데 3으로 끝나는 수
    d[i][j] += (d[i - 1][k]) % 10007 로 점화식
    
	
*/

int main() {


	int n;
	cin >> n;

	long long** d = new long long* [1001];
	for (int i = 0; i < 1001; i++) {
		d[i] = new long long[10];
	}

	//long long [10][3] digit 수가 10인데 3으로 끝나는 수

	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i < 1001; i++) {
		for (int j = 0; j < 10; j++) {
			d[i][j] = 0;
			for (int k = j; k < 10; k++) {
				d[i][j] += (d[i - 1][k]) % 10007;
			}
		}
	}
	

	long long* memo = new long long[1001];

	for (int i = 1; i <= n; i++) {
		memo[i] = 0;
		for (int j = 0; j < 10; j++) {
			memo[i] += (d[i][j]);
		}
		memo[i] %= 10007;
	}

	cout << memo[n];
	return 0;
}
