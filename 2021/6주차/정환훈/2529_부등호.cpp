#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/10
    아이디어 : dfs와 백트래킹

*/

int boo_num; // 부등호 개수
char boo_str[100]; // 부등호 문자열
bool used[10] = { 0, }; // 해당 숫자 썼나?
vector<string> answer;
void dfs(int d, string s) { // depth와 현재 string

	if (d == boo_num + 1) { // 숫자 개수 == 부등호 개수 + 1개 => 끝 도달
		answer.push_back(s);
		return;
	}

	for (int i = 0; i < 10; i++) { // 쓸 수 있는 숫자가 0~9

		int last = stoi(s) % 10; // 비교할 대상은 마지막 숫자

		if (boo_str[d - 1] == '<') { // 이번 부등호가 < 면 ( 다음 숫자가 더 커야 함 )
			if (i >= last && i + 1 < 10 && used[i + 1] == false) { // 탐색 조건 : 탐색 숫자가 마지막 숫자보다 커야 하고 그 숫자를 안 썼어야 한다
				used[i + 1] = true; // i + 1 넣어서 탐색
				dfs(d + 1, s + to_string(i + 1));
				used[i + 1] = false; // 아니면 아닌대로 탐색 진행
			}
		}
		else if (boo_str[d - 1] == '>') { // 다음 숫자가 더 작아야 함
			if (i <= last && i - 1 >= 0 && used[i - 1] == false) { // 탐색 조건 : 탐색 숫자가 마지막 숫자보다 작아야 하고 그 숫자를 안 썼어야 한다
				used[i - 1] = true; // i - 1 넣어서 탐색
				dfs(d + 1, s + to_string(i - 1));
				used[i - 1] = false; // 아니면 아닌대로 탐색
			}
		}
	}

}

void input() {
	cin >> boo_num; 
	for (int i = 0; i < boo_num; i++) {
		cin >> boo_str[i];
	}
}

void solve() {

	for (int i = 0; i < 10; i++) { // 시작 숫자가 0 ~ 9
		used[i] = true;
		dfs(1, to_string(i));
		used[i] = false;
	}

	sort(answer.begin(), answer.end());

	cout << answer.back() << endl;
	cout << answer.front();

}

int main() {

	input();
	solve();

	return 0;
}