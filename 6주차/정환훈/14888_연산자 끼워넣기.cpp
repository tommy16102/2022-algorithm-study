#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/11
    아이디어 : dfs 백트래킹
*/

int n; // 숫자 개수
vector<int> nums; // 숫자 배열
vector<int> ops; // 연산자[4] 의 각각 개수
vector<int> answers;

void dfs(int depth,int s) {
	if (depth == n) { // 연산자 개수 == 숫자 개수 - 1 이므로 같아지게 되는 순간 끝
		answers.push_back(s);
		return;
	}

	if (ops[0] > 0) { // + 가능
		ops[0]--; // + 써서 진행
		dfs(depth + 1, s + nums[depth]);
		ops[0]++; // 안써서 진행 이하 같음
	}
	if (ops[1] > 0) { // - 가능
		ops[1]--;
		dfs(depth + 1, s - nums[depth]);
		ops[1]++;
	}
	if (ops[2] > 0) { // * 가능
		ops[2]--;
		dfs(depth + 1, s * nums[depth]);
		ops[2]++;
	}
	if (ops[3] > 0) { // / 가능
		ops[3]--;
		dfs(depth + 1, s / nums[depth]);
		ops[3]++;
	}


}

void input() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		ops.push_back(temp);
	}

}



void solve() {

	dfs(1, nums[0]);
	for (int i = 0; i < answers.size(); i++) {
		//cout << answers[i] << endl;
	}

	sort(answers.begin(), answers.end());

	cout << answers.back() << endl << answers.front();
}

int main() {

	input();
	solve();

	return 0;
}



