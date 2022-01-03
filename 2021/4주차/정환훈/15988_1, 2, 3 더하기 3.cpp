#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

    푼 날짜 : 2021/07/28
    기본 아이디어 : DP 
    잘 생각해보면 세개 항 더한거임
    근데 이제 long long을 곁들인

	
*/

int main() {

	long long* memo = new long long[1000001];

	memo[1] = 1; // 11
	memo[2] = 2; // 11 2
	memo[3] = 4;// 111 12 21 3
	memo[4] = 7; // 1 + memo[3] + memo[2] + memo[1]


	for (int i = 5; i <= 1000000; i++) {
		memo[i] = (memo[i - 1] + memo[i - 2] + memo[i - 3]) % 1000000009;
	}


	int t;
	cin >> t;
	vector<int> n;

	for (int i = 0; i < t; i++) {
		int temp; cin >> temp;
		n.push_back(temp);
	}

	for (int i = 0; i < n.size(); i++) {
		cout << memo[n[i]] << endl;
	}


	return 0;
}
