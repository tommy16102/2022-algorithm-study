#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

소요일을 고려하여 가능한 N일을 넘지않는 소요일 범위 내의 상담 일을 찾아낸다.

*/

int max = 0;
int N;
vector<int> T;
vector<int> P;

void dfs(int index,int sum) {
	if (sum > ::max) ::max = sum;
	int nextIndex = index + T[index];
	if (index + T[index] > N) return;

	for (int i = nextIndex;i < N;i++) {
		if (i + T[i] > N) continue;
		dfs(i, sum + P[i]);
	}
}

int main() {
	
	cin >> N;

	int x, y;
	for (int i = 0;i < N;i++) {
		cin >> x >> y;
		T.push_back(x);
		P.push_back(y);
	}

	for (int i = 0;i < N;i++) {
		if (i + T[i] > N) continue;
		dfs(i,P[i]);
	}

	cout << ::max << endl;
}
