#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*

    푼 날짜 : 2021/07/29
    기본 아이디어 : DP 
    d[i][j] = 합이 i인데 마지막 j(1~3)을 더하며 끝나는 경우의 수
    로 ex)d[7][1] = d[6][2] + d[6][3]임을 이용

	
*/

int main() {

	long long** d = new long long* [100001];
	for (int i = 0; i < 100001; i++) {
		d[i] = new long long[5];
		for (int j = 0; j < 5; j++) {
			d[i][j] = 0;
		}
	}

	int t;
	cin >> t;

	d[1][1] = 1;
	d[1][2] = 0;
	d[1][3] = 0;

	d[2][1] = 0;
	d[2][2] = 1;
	d[2][3] = 0;

	d[3][1] = 1; // 21
	d[3][2] = 1; // 12
	d[3][3] = 1; // 3

	d[4][1] = 2; // 31
	d[4][2] = 0;
	d[4][3] = 1; // 13

	d[5][1] = 1; // 131
	d[5][2] = 2; // 212 32
	d[5][3] = 1; // 23


	d[6][1] = d[5][2] + d[5][3]; // 4
	d[6][2] = d[4][1] + d[4][3]; // 3
	d[6][3] = d[3][1] + d[3][2]; // 3

	for (int i = 7; i < 100001; i++) {

		for (int j = 1; j <= 3; j++) {
			
			for (int k = 1; k <= 3; k++) {
				if (k != j) {
					d[i][j] += (d[i - j][k]) % 1000000009;
				}
			}

		}
	}


	vector<int> n;
	long long* memo = new long long[100001];

	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		n.push_back(temp);
	}

	for (int i = 1; i < 100001; i++) {
		memo[i] = (d[i][1] + d[i][2] + d[i][3]) % 1000000009;
	}

	for (int i = 0; i < n.size(); i++) {
		cout << memo[n[i]] << endl;
	}

	return 0;
}
