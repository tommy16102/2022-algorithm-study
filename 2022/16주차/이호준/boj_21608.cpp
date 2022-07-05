/*******************************************************************
Algorithm Study
Baekjoon OJ 구현
21608 상어 초등학교
2022/07/05 이호준
# 아이디어
1. 빡구현 문제 삼성전자 기출.
*******************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

typedef struct STUDENT {
	int number;
	vector<int> friends;
};

vector<STUDENT> students;
vector<vector<int>> map;
unordered_map<int, vector<int>> student_map;

bool compare(const pair<int,int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int calculateFinalScores(int size) {
	int total_student_num = size * size;
	int total_score = 0;
	for (int i = 0; i < total_student_num; i++) {
		int x = i / size;
		int y = i % size;
		int current_student = map[x][y];
		vector<int> friends_list = student_map[current_student];
		int neighbor_friend_count = 0;
		for (int j = 0; j < 4; j++) {
			int neighbor_x = x + dx[j];
			int neighbor_y = y + dy[j];
			if (neighbor_x >= 0 && neighbor_x < size && neighbor_y >= 0 && neighbor_y < size) {
				for (int a = 0; a < 4; a++) {
					if (map[neighbor_x][neighbor_y] == friends_list[a]) {
						neighbor_friend_count++;
						break;
					}
				}
			}
		}
		if (neighbor_friend_count == 1) {
			total_score += 1;

		}
		else if (neighbor_friend_count == 2) {
			total_score += 10;
		}
		else if (neighbor_friend_count == 3) {
			total_score += 100;
		}
		else if (neighbor_friend_count == 4) {
			total_score += 1000;
		}
	}

	return total_score;
}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;

	cin >> N;

	int student_size = N * N;

	for (int i = 0; i < student_size; i++) {
		int num;
		vector<int> tmp(4, 0);
		cin >> num;
		for (int j = 0; j < 4; j++) {
			cin >> tmp[j];
		}
		students.push_back({ num, tmp });
		student_map[num] = tmp;
	}

	map = vector<vector<int>>(N, vector<int>(N, 0));

	/*for (auto a : students) {
		cout << a.number << ' ';
		for (auto b : a.friends)
			cout << b << " ";
		cout << "\n";
	}*/

	for (int i = 0; i < student_size; i++) {
		int current_student = students[i].number;
		vector<int> friends_vector = students[i].friends;
		int max_neighbor_count = 0;
		vector<pair<int, int>> first_list;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (map[a][b] == 0) {
					int current_neighbor_count = 0;
					// 1. 비어있는 칸 중에서 좋아하는 인접한 칸이 가장 많은 자리 정하기
					for (int j = 0; j < 4; j++) {
						int neighbor_x = a + dx[j];
						int neighbor_y = b + dy[j];
						if (neighbor_x >= 0 && neighbor_x < N && neighbor_y >= 0 && neighbor_y < N) {
							for (int k = 0; k < 4; k++) {
								if (map[neighbor_x][neighbor_y] == friends_vector[k]) {
									current_neighbor_count++;
									break;
								}
							}
						}
					}
					// 최대 인접한 칸이 변경되는 경우
					if (max_neighbor_count < current_neighbor_count) {
						max_neighbor_count = current_neighbor_count;
						first_list.clear();
						first_list.push_back({ a, b });
					}else if (max_neighbor_count == current_neighbor_count) {
						first_list.push_back({ a, b });
					}
				}
				
			}
		}
		// 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정함
		if (first_list.size() > 1) {
			vector<pair<int,int>> second_list;
			int max_empty_count = 0;
			for (int i = 0; i < first_list.size(); i++) {
				int current_empty_count = 0;
				int current_x = first_list[i].first;
				int current_y = first_list[i].second;
				for (int j = 0; j < 4; j++) {
					int neighbor_x = current_x + dx[j];
					int neighbor_y = current_y + dy[j];
					if (neighbor_x >= 0 && neighbor_x < N && neighbor_y >= 0 && neighbor_y < N) {
						if (map[neighbor_x][neighbor_y] == 0)
							current_empty_count++;
					}
				}

				if (max_empty_count < current_empty_count) {
					max_empty_count = current_empty_count;
					second_list.clear();
					second_list.push_back({ current_x, current_y });
				}
				else if (max_empty_count == current_empty_count){
					second_list.push_back({ current_x, current_y });
				}
			}
			// 3. 2를 만족하는 칸도 여러개 인 경우, 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러개 이면, 열의 번호가 가장 작은 칸으로
			if (second_list.size() > 1) {
				sort(second_list.begin(), second_list.end(), compare);
			}
			map[second_list[0].first][second_list[0].second] = current_student;
		}
		else {
			map[first_list[0].first][first_list[0].second] = current_student;
		}
		
	}

	/*for (auto a : map) {
		for (auto b : a)
			cout << b << " ";
		cout << "\n";
	}*/
	cout << calculateFinalScores(N);

	return 0;

}