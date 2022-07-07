#include <iostream>
#include <vector>
using namespace std;

int N, arr[23][23], fav[23*23][23*23];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };
int answer = 0;

pair<int,int> checkArr(int n) {
	int I, J;
	int friendCnt = -1;
	int blankCnt = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] != 0) continue;
			int fCnt = 0;
			int bCnt = 0;
			for (int x = 0; x < 4; x++) {
				int nextI = i + moveI[x];
				int nextJ = j + moveJ[x];
				if (nextI < 1 || nextJ < 1 || nextI > N || nextJ > N) continue;
				if (fav[n][arr[nextI][nextJ]] == 1) fCnt++;
				else if (arr[nextI][nextJ] == 0) bCnt++;
			}

			if (fCnt > friendCnt) {
				I = i;
				J = j;
				friendCnt = fCnt;
				blankCnt = bCnt;
			}
			else if (fCnt == friendCnt && bCnt > blankCnt) {
				I = i;
				J = j;
				blankCnt = bCnt;
			}
		}
	}

	return { I, J };
}

void pushArr(int n) {
	pair<int, int> index = checkArr(n);
	arr[index.first][index.second] = n;
}

void calc() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			int from = arr[i][j];
			for (int x = 0; x < 4; x++) {
				int nextI = i + moveI[x];
				int nextJ = j + moveJ[x];
				if (nextI < 1 || nextJ < 1 || nextI > N || nextJ > N) continue;
				int to = arr[nextI][nextJ];
				if (fav[from][to] == 1) cnt++;
			}
			int add = 0;
			if (cnt == 1) add = 1;
			else if (cnt == 2) add = 10;
			else if (cnt == 3) add = 100;
			else if (cnt == 4) add = 1000;
			answer += add;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N;
	vector<int> v;
	for (int i = 1; i <= N * N; i++) {
		int from;
		cin >> from;
		v.push_back(from);
		for (int j = 0; j < 4; j++) {
			int to;
			cin >> to;
			fav[from][to] = 1;
		}
	}

	for (int i = 0; i < N * N; i++) {
		pushArr(v[i]);
	}

	calc();

	cout << answer;
}