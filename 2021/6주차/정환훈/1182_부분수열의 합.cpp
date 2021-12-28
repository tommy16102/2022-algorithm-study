#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/11
    아이디어 : nCr개 뽑아서 해결

*/

int n;
int s;
int answer = 0;
vector<int> nums;
void input() {

	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
}

void test(int r) {
	vector<int> combination; // 조합 뽑기에 활용할 combi

	for (int i = 0; i < r; i++) { // r개의 0
		combination.push_back(0);
	}

	for (int i = 0; i < n - r; i++) { // n-r개의 1
		combination.push_back(1);
	}


	do {

		int candy = 0; // 후보

		for (int i = 0; i < nums.size(); i++) {
			if (combination[i] == 0) { // 0인 위치 값들만 골라(nCr개 조합) 더하기
				candy += nums[i];
			}
		}

		if (candy == s) { // 부분수열 찾으면

			for (int i = 0; i < combination.size(); i++) {
				//cout << combination[i] << " ";
			}

			//cout << endl;
			answer++; // 답 추가
		}

	} while (next_permutation(combination.begin(), combination.end()));

}

void solve() {

	for (int r = 1; r <= n; r++) { // nC1 nC2 nC3 nC4 ... nC4
		test(r); // nCr test
	}

	cout << answer;
}

int main() {

	input();
	solve();

	return 0;
}



