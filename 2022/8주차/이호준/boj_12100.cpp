/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
12100 2048(Easy)
2022/03/21 이호준
# 아이디어
1. 배열을 움직이는 것이다.
주어진 조건대로 풀면되는데
내 생각대로 코드를 짜지 못했다.
생각과 다르게 코드를 짜는부분이 존재했다.
좀 더 신중하게 코드를 짜고 많이 짜봐야할 것 같다.
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int max_value;

void dfs(int count, vector<vector<int>> board) {
	int n = board.size();

	if (count == 5) {
		return;
	}

	/*for (auto a : board) {
		for (auto b : a)
			cout << b << " ";
		cout << "\n";
	}
	cout << "\n\n";*/

	for (int a = 0; a < 4; a++) {
		vector<vector<int>> next(n, vector<int>(n, 0));
		if (a == 0) {
			// 왼쪽
			for (int i = 0; i < n; i++) {
				vector<int> row;
				for (int j = 0; j < n; j++) {
					if (board[i][j] != 0) {
						row.push_back(board[i][j]);
					}
				}
				if (!row.empty()) {
					if (row.size() == 1) {
						next[i][0] = row[0];
					}
					else {
						int k = 0;
						for (int j = 0; j < row.size() - 1; j++) {
							if (k >= n) {
								break;
							}
							if (row[j] == row[j + 1]) {
								next[i][k] = row[j] * 2;
								if (next[i][k] > max_value) {
									max_value = next[i][k];
								}
								j++;
								k++;
								if (j == row.size() - 2) {
									next[i][k] = row[j + 1];
								}
							}
							else {
								next[i][k++] = row[j];
								if (j == row.size() - 2) {
									next[i][k] = row[j + 1];
								}
							}
						}
					}	
				}
			}
			dfs(count + 1, next);
		}
		else if (a == 1) {
			// 오른쪽
			for (int i = 0; i < n; i++) {
				vector<int> row;
				for (int j = n-1; j >=0; j--) {
					if (board[i][j] != 0) {
						row.push_back(board[i][j]);
					}
				}
				if (!row.empty()) {
					if (row.size() == 1) {
						next[i][n - 1] = row[0];
					}
					else {
						int k = n - 1;
						for (int j = 0; j < row.size() - 1; j++) {
							if (k < 0) {
								break;
							}
							if (row[j] == row[j + 1]) {
								next[i][k] = row[j] * 2;
								if (next[i][k] > max_value) {
									max_value = next[i][k];
								}
								j++;
								k--;
								if (j == row.size() - 2) {
									next[i][k] = row[j + 1];
								}
							}
							else {
								next[i][k--] = row[j];
								if (j == row.size() - 2) {
									next[i][k] = row[j + 1];
								}
							}
						}
					}				
				}		
			}
			dfs(count + 1, next);
		}
		else if (a == 2) {
			// 위로
			for (int i = 0; i < n; i++) {
				vector<int> column;
				for (int j = 0; j < n; j++) {
					if (board[j][i] != 0) {
						column.push_back(board[j][i]);
					}
				}
				if (!column.empty()) {
					if (column.size() == 1) {
						next[0][i] = column[0];
					}
					else {
						int k = 0;
						for (int j = 0; j < column.size() - 1; j++) {
							if (k >= n) {
								break;
							}
							if (column[j] == column[j + 1]) {
								next[k][i] = column[j] * 2;
								if (next[k][i] > max_value) {
									max_value = next[k][i];
								}
								k++;
								j++;
								if (j == column.size() - 2) {
									next[k][i] = column[j + 1];
								}
							}
							else {
								next[k++][i] = column[j];
								if (j == column.size() - 2) {
									next[k][i] = column[j + 1];
								}
							}
						}
					}	
				}
				
			}
			dfs(count + 1, next);
		}
		else {
			// 아래
			for (int i = 0; i < n; i++) {
				vector<int> column;
				for (int j = n-1; j >=0; j--) {
					if (board[j][i] != 0) {
						column.push_back(board[j][i]);
					}
				}
				if (!column.empty()) {
					if (column.size() == 1) {
						next[n - 1][i] = column[0];
					}
					else {
						int k = n - 1;
						for (int j = 0; j < column.size() -1 ; j++) {
							if (k < 0) {
								break;
							}
							if (column[j] == column[j + 1]) {
								next[k][i] = column[j] * 2;
								if (next[k][i] > max_value) {
									max_value = next[k][i];
								}
								k--;
								j++;
								if (j == column.size()-2) {
									next[k][i] = column[j + 1];
								}
							}
							else {
								next[k--][i] = column[j];
								if (j == column.size() - 2) {
									next[k][i] = column[j + 1];
								}
							}
						}
					}	
				}
			}
			dfs(count + 1, next);
		}
	}
}


int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

	int n;

	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			board[i][j] = temp;
			if (max_value < temp) {
				max_value = temp;
			}
		}
	}

	//for (auto a : board) {
	//	for (auto b : a)
	//		cout << b << " ";
	//	cout << "\n";
	//}

	dfs(0, board);

	cout << max_value;

	return 0;
}