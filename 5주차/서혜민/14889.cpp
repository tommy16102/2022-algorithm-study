#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*

2021.08.09 서혜민

재귀를 통해 1부터 N중 N/2개를 가지는 가능한 조합을 start 벡터에 넣어주면
calc()를 통해서 start 벡터에 없는 조합을 link 벡터에 넣어준뒤, 모든 쌍의 능력치를 합한 뒤, min보다 작다면 min에 저장.

*/

int arr[21][21];
int N;
vector<int> start;
vector<int> link;
bool checked[21];
int min = INT_MAX;

void calc();
void makeTeam(int n, int count) {
	if(start.size() == N / 2) {
		calc();
	}
	else if (start.size() > N / 2) return;
	else {
		for (int i = n + 1;i <= N - (N / 2 - start.size())+1;i++) {
			start.push_back(i);
			makeTeam(i, count + 1);
			start.pop_back();
		}
	}
}

void calc() {
	for (int i = 1;i <= N;i++) {
		auto it = find(start.begin(), start.end(), i);
		if (it == start.end()) {
			link.push_back(i);
		}
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 0;i < N / 2;i++) {
		for (int j = 0;j < N / 2;j++) {
			if (i == j) continue;
			sum1 += arr[start[i]][start[j]];
			sum2 += arr[link[i]][link[j]];
		}
	}
	if (::min > abs(sum1 - sum2)) ::min = abs(sum1 - sum2);

	link.clear();
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1;i <= N-(N/2-1);i++) {
		start.push_back(i);
		makeTeam(i, 1);
		start.pop_back();
	}
	cout << ::min << endl;
}
