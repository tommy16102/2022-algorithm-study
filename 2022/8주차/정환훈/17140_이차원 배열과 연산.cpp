#include <bits/stdc++.h>
using namespace std;

int r;
int c;
int k;
int rsize = 0;
int csize = 0;
int ary[101][101];
int freq[101];
int result[101][101];


void input() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ary[i][j];
		}
	}
}

void print() {
	cout << "+======================\n";

	for (int i = 0; i < rsize; i++) {
		for (int j = 0; j < csize; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	cout << "+======================\n";
}

void R() {

	int newCsize = 0;
	for (int i = 0; i < rsize; i++) {
		vector<int> line;
		vector<pair<int, int>> nums; // <나온 횟수, 값>

		for (int j = 0; j < 101; j++) {
			freq[j] = 0;
		}

		for (int j = 0; j < csize; j++) {
			line.push_back(ary[i][j]);
		}
		for (int j = 0; j < line.size(); j++) {
			freq[line[j]]++;
		}

		for (int j = 0; j < line.size(); j++) {
			nums.push_back({ freq[line[j]], line[j] });
		}

		// 정렬 및 중복제거
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());

		// 값이 0인 경우 제거
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j].second == 0) {
				nums.erase(nums.begin() + j);
			}
		}


		int s = nums.size();
		int msize = min(50, s);

		// 값, 나온 횟수 순으로 입력됨
		for (int j = 0; j < msize; j++) {
			result[i][2 * j] = nums[j].second;
			result[i][2 * j + 1] = nums[j].first;
		}

		// 남은 자리 0 채우기
		for (int j = 2 * msize; j < csize; j++) {
			result[i][j] = 0;
			
		}

		// csize 업데이트
		newCsize = max(newCsize, 2 * s);

	}
	csize = newCsize;
}

void C() {

	int newRsize = 0;
	for (int i = 0; i < csize; i++) {
		vector<int> line;
		vector<pair<int, int>> nums; // <freq, size>

		for (int j = 0; j < 101; j++) {
			freq[j] = 0;
		}

		for (int j = 0; j < rsize; j++) {
			line.push_back(ary[j][i]);
		}
		for (int j = 0; j < line.size(); j++) {
			freq[line[j]]++;
		}

		for (int j = 0; j < line.size(); j++) {
			nums.push_back({ freq[line[j]], line[j] });
		}


		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());

		for (int j = 0; j < nums.size(); j++) {
			if (nums[j].second == 0) {
				nums.erase(nums.begin() + j);
			}
		}

		int s = nums.size();
		int msize = min(50, s);

		for (int j = 0; j < msize; j++) {
			result[2 * j][i] = nums[j].second;
			result[2 * j + 1][i] = nums[j].first;
		}

		for (int j = 2 * msize; j < rsize; j++) {
			result[j][i] = 0;

		}
		newRsize = max(newRsize, 2 * s);

	}
	rsize = newRsize;
}

void solve() {
	rsize = 3;
	csize = 3;

	for (int t = 0; t < 101; t++) {
		if (ary[r - 1][c - 1] == k) {
			cout << t;
			return;
		}

		if (rsize >= csize) {
			R();
		}

		else {
			C();
		}

		
		// result로만 계산한 후 ary에 result 값을 옮겨준다
		for (int i = 0; i < rsize; i++) {
			for (int j = 0; j < csize; j++) {
				ary[i][j] = result[i][j];
			}
		}
	}
	cout << -1;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}