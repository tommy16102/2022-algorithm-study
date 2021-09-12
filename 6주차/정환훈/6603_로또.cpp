#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/10
    아이디어 : nCr개 뽑아서 해결

*/

vector<int> s; // 전체 집합 벡터
vector<int> combi; // nCr을 위한 임시 벡터

int num;
void input() {

	cin >> num;
	if (num == 0) { // 끝나는 경우
		return;
	}

	combi.clear(); // 한 번 할때마다 초기화
	s.clear();

	for (int i = 0; i < num; i++) { // 값 받기
		int temp;
		cin >> temp;
		s.push_back(temp);
	}
	for (int i = 0; i < 6; i++) { // 0을 6개 박고 나머지 1로 채우고 next_permutation으로 돌릴 것
		combi.push_back(0);
	}
	for (int i = 0; i < s.size() - 6; i++) {
		combi.push_back(1);
	}
	
}

void solve() {

	do {
		input();
		if (num == 0)  // 끝나는 경우만 따로 처리
			break;

		do {
			vector<int> k; // combi에서 0인 애들만 모아놓은 집합 벡터. 한바퀴 돌때마다 새로 선언


			for (int i = 0; i < combi.size(); i++) {
				if (combi[i] == 0) { // 0이면 값으로 선택
					k.push_back(s[i]);
				}
			}

			for (int i = 0; i < k.size(); i++) { // 출력
				cout << k[i] << " ";
			}
			cout << endl;
		} while (next_permutation(combi.begin(), combi.end())); // nCr 반복

		cout << endl; // 출력 형태 맞추기

	} while (true);

}

int main() {

	solve();

	return 0;
}



