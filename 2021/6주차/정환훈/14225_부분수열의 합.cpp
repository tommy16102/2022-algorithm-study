#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/12
    아이디어 : nCr 돌리는 브루트포스
*/

int n; // 숫자 개수
vector<int> numbers; // 숫자 배열
bool* visited; // 해당 숫자가 완성되는지?
int max_value; // 배열이 만들 수 있는 가장 큰 수

void input() {
	cin >> n;
	max_value = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
		max_value += temp;
	}

	visited = new bool[max_value + 1];
	for (int i = 0; i < max_value + 1; i++) {
		visited[i] = false;
	}
}

void nCr(int r) { // nCr 골라서 수열의 합 체크

	vector<int> combi;
	for (int i = 0; i < r; i++) { // r개의 0
		combi.push_back(0);
	}
	for (int i = 0; i < n - r; i++) { // n-r개의 1
		combi.push_back(1);
	}

	do {
		int result = 0;

		for (int i = 0; i < numbers.size(); i++) {
			if (combi[i] == 0) { // 0인 애들만 모아서 합 만듬
				result += numbers[i];
			}
		}

		visited[result] = true; // 해당 숫자는 만들 수 있다


	} while (next_permutation(combi.begin(), combi.end()));

}


void solve() {

	for (int i = 1; i <= n; i++) { // 1부터 n까지 nCr 돌림
		nCr(i);
	}

	for (int i = 1; i <= max_value; i++) {
		if (visited[i] == false) { // 가장먼저 아닌놈 발견하면 출력
			cout << i;
			return;
		}
	}

	cout << max_value + 1; // 끝까지 도달시 만들 수 있는 최댓값+1 출력


}

int main() {

	input();
	solve();

	return 0;
}
