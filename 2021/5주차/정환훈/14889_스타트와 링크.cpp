#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 날짜 : 2021/08/04
    아이디어 : next permutation을 활용하여 조합 구하기

*/

void judge(vector<int>& start, vector<int>& link, int* min, int** stat) {

	int start_stat = 0; // 스타트 팀 총합
	int link_stat = 0; // 링크 팀 총합


	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			if (i != j) { // 각각의 팀 총합 구하기
				start_stat += stat[start[i]][start[j]]; // 2 3 5
				link_stat += stat[link[i]][link[j]];
			}
		}
	}

	if (abs(start_stat - link_stat) < *min) { // 최솟값 갱신
		*min = abs(start_stat - link_stat);
	}


}


int main() {

	int num;
	cin >> num;
	int** stat = new int* [num + 1];
	for (int i = 0; i < num + 1; i++) {
		stat[i] = new int[num + 1];
	}

	for (int i = 1; i < num + 1; i++) {
		for (int j = 1; j < num + 1; j++) {
			cin >> stat[i][j];
		}
	}

	int min = 1234567;



	vector<int> n;
	for (int i = 0; i < num; i++) {
		n.push_back(i + 1);
	}

	// 0과1을 저장 할 벡터 생성
	vector<int> ind;

	// k=4, 4개를 뽑으니까
	int k = num / 2;

	// k개의 1 추가
	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}

	// 2개(6개-2개)의 0 추가
	for (int i = 0; i < n.size() - k; i++) {
		ind.push_back(0);
	}

	// 정렬
	sort(ind.begin(), ind.end());


	do { // 조합 nCr 팀원 뽑아서 총합 세는 완전탐색

		vector<int> start; vector<int> link;

		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 0)
				start.push_back(i + 1);
			else
				link.push_back(i + 1);
		}

		judge(start, link, &min, stat);
		if (min == 0) break;

	} while (next_permutation(ind.begin(), ind.end()));

	cout << min;

	return 0;
}
