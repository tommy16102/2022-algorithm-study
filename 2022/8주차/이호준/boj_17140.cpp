/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
17140 이차원 배열과 연산
2022/03/20 이호준
# 아이디어
1. 순수 구현이다.
문제상황을 정확히 이해하고
정확히 생각한대로 구현하는 연습이필요하다.
생각보다 자잘한 실수가 많아 논리는 맞는데 틀리는 경우가 많다.

문제가 어렵다기보단 멘탈싸움이랄까. 코드를 많이 짜본사람한테 유리한 것 같다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[100][100];

int count_value[101];

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}else {
		return false;
	}
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int r, c, k;

	cin >> r >> c >> k;
	r--; c--;

	int max_column = 3;
	int max_row = 3;

	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_column; j++) {
			cin >> map[i][j];
		}
	}

	int time = 0;

	while (1) {
		if (time > 100) {
			time = -1;
			break;
		}
		if (map[r][c] == k) {
			break;
		}


		if (max_row >= max_column){
			for (int i = 0; i < max_row; i++) {
				vector<int> current_row;
				for (int j = 0; j < max_row; j++) {
					if (map[i][j] != 0) {
						current_row.push_back(map[i][j]);
						count_value[map[i][j]]++;
					}
				}
				if (!current_row.empty()) {
					sort(current_row.begin(), current_row.end());
					current_row.erase(unique(current_row.begin(), current_row.end()), current_row.end());
					vector<pair<int, int>> now;
					for (int a = 0; a < current_row.size(); a++) {
						now.push_back({ current_row[a], count_value[current_row[a]] });
					}

					sort(now.begin(), now.end(), compare);

					for (int a = 0; a < now.size()*2 && a < 99; a+=2) {
						map[i][a] = now[a/2].first;
						map[i][a + 1] = now[a/2].second;
					}

					for (int a = now.size() * 2; a < max_row; a++) {
						if (map[i][a] != 0) {
							map[i][a] = 0;
						}
					}

					if (i == 0) {
						max_column = now.size() * 2;
						if (max_column > 100) max_column = 100;
					}

					if (max_column < now.size() * 2) {
						max_column = now.size() * 2;
						if (max_column > 100) max_column = 100;
					}

					for (int a = 0; a < 101; a++) {
						count_value[a] = 0;
					}

				}
			}
		}
		else {
			for (int i = 0; i < max_column; i++) {
				vector<int> current_column;
				for (int j = 0; j < max_column; j++) {
					if (map[j][i] != 0) {
						current_column.push_back(map[j][i]);
						count_value[map[j][i]]++;
					}
				}
				if (!current_column.empty()) {
					sort(current_column.begin(), current_column.end());
					current_column.erase(unique(current_column.begin(), current_column.end()), current_column.end());
					vector<pair<int, int>> now;
					for (int a = 0; a < current_column.size(); a++) {
						now.push_back({ current_column[a], count_value[current_column[a]] });
					}
					sort(now.begin(), now.end(), compare);

					for (int a = 0; a < now.size() * 2 && a < 99; a += 2) {
						map[a][i] = now[a/2].first;
						map[a+1][i] = now[a/2].second;
					}
					for (int a = now.size() * 2; a < max_column; a++) {
						if (map[a][i] != 0) {
							map[a][i] = 0;
						}
					}
					if (i == 0) {
						max_row = now.size() * 2;
						if (max_row > 100) max_row = 100;
					}

					if (max_row < now.size() * 2) {
						max_row = now.size() * 2;
						if (max_row > 100) max_row = 100;
					}

					for (int a = 0; a < 101; a++) {
						count_value[a] = 0;
					}
				}
				
			}
		}

		/*cout << "max_row : " << max_row << "    max_col : " << max_column << "\n";

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";*/
		

		time++;
	}
	
	cout << time;

	return 0;
}