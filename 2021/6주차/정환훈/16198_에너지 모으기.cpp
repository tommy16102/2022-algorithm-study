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

int n; // 에너지 개수
vector<int> energy; // 에너지 배열
vector<int> answers;
void dfs(int depth, int s, int k) {
	if (depth == n - 1) { // n - 2 개를 터뜨렸으면 앞뒤빼고 다 없어졌으니 저장
		answers.push_back(s);
		return;
	}

	for (int i = 1; i < k; i++) { // 에너지 인덱스 1 ~ k 돌아가면서 고름 ( 초기값 : n - 1)
		int save = energy.at(i); // 삭제할 에너지값 보존
		int add = energy.at(i - 1) * energy.at(i + 1); // 더해지는 에너지 값
		energy.erase(energy.begin() + i); // 해당 인덱스 삭제하고 진행
		dfs(depth + 1, s + add, k - 1);
		energy.insert(energy.begin() + i, save); // 삭제 안하고 진행
	}
}


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		energy.push_back(temp);
	}
}



void solve() {

	dfs(1, 0, n - 1);
	sort(answers.begin(), answers.end());

	//for (int i = 0; i < answers.size(); i++) {
	//	cout << answers[i] << endl;
	//}
	cout << answers.back();
}

int main() {

	input();
	solve();

	return 0;
}



