#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

/*

2022.3.19

배열의 row, column 길이에 따라서 R, C 연산을 해준 뒤
해당 배열에 맞게 row나 column을 업데이트 한 뒤 이를 맞는 값을 찾을 때까지 반복.

*/

int A[101][101];
int cnt[101];

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first <= p2.first;
	return p1.second <= p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 1;i <= 3;i++) {
		for (int j = 1;j <= 3;j++) {
			cin >> A[i][j];
		}
	}

	int ans = 0;
	int row = 3, col = 3;

	while (ans <= 100) {
		if (A[r][c] == k) {
			cout << ans;
			return 0;
		}

		if (row >= col) {
			for (int i = 1;i <= row;i++) {
				set<int> set;
				for (int j = 1;j <= col;j++) {
					if (A[i][j] == 0) continue;
					set.insert(A[i][j]);
					cnt[A[i][j]]++;
				}
				vector<pair<int, int>> v;
				for (auto it = set.begin(); it != set.end();it++) {
					int num = *it;
					v.push_back({ num, cnt[num]});
				}
				sort(v.begin(), v.end(), comp);

				for (int j = 1;j <= col;j++) A[i][j] = 0;

				for (int j = 1;j <= v.size();j++) {
					A[i][j * 2 - 1] = v[j - 1].first;
					A[i][j * 2] = v[j - 1].second;
				}
				memset(cnt, 0, sizeof(cnt));
				col = max(col, int(v.size()) * 2);

			}
		}
		else {
			for (int i = 1;i <= col;i++) {
				set<int> set;
				for (int j = 1;j <= row;j++) {
					if (A[j][i] == 0) continue;
					set.insert(A[j][i]);
					cnt[A[j][i]]++;
				}
				vector<pair<int, int>> v;
				for (auto it = set.begin(); it != set.end();it++) {
					int num = *it;
					v.push_back({ num, cnt[num] });
				}
				sort(v.begin(), v.end(), comp);

				for (int j = 1;j <= row;j++) A[j][i] = 0;

				for (int j = 1;j <= v.size();j++) {
					A[j * 2 - 1][i] = v[j - 1].first;
					A[j * 2][i] = v[j - 1].second;
				}
				memset(cnt, 0, sizeof(cnt));
				row = max(row, int(v.size()) * 2);
			}
		}
		ans++;
	}
	cout << -1;
}
