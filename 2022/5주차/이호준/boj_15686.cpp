/*******************************************************************
Algorithm Study
Baekjoon OJ BF
15686 치킨 배달
2022/02/14 이호준
# 아이디어
1. 조합을 이용해 chicken 집을 1개부터 max개까지 선택하여
BF로 최단거리를 구한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, max;
	cin >> n >> max;

	int answer = 210000000;

	vector<vector<int>> map(n, vector<int>(n, 0));
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) {
				house.push_back({ i, j });
			}
			else if (temp == 2) {
				chicken.push_back({ i, j });
			}
		}
	}

	int current_store_size = chicken.size();

	vector<bool> combination(current_store_size, false);


	for (int i = 1; i <= max; i++) {
        // nCi
		for (int j = current_store_size-i; j < current_store_size; j++) {
			combination[j] = true;
		}
		do {
			vector < pair<int, int>> selected;
            // i 개 치킨집 selection
			for (int i = 0; i < current_store_size; i++) {
				if (combination[i]) {
					selected.push_back({ chicken[i] });
				}
			}

            // 해당 case distance 구하기
			int current_answer = 0;
			for (int a = 0; a < house.size(); a++) {
				int min = 2100000000;
				int current_x = house[a].first;
				int current_y = house[a].second;
				for (int b = 0; b < selected.size(); b++) {
					int current_distance = abs(current_x - selected[b].first) + abs(current_y - selected[b].second);
					if (min > current_distance) {
						min = abs(current_x - selected[b].first) + abs(current_y - selected[b].second);
					}
				}
				current_answer += min;
			}
			if (answer > current_answer) {
				answer = current_answer;
			}

		} while (next_permutation(combination.begin(), combination.end()));
	}

	cout << answer;

	return 0;
}