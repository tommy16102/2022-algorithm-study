#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*

2021.08.16 서혜민

구슬을 제거할 수 있는 두번째 위치부터 마지막-1 위치까지 구슬을 제거하면서
합을 더해주는 과정을 재귀적으로 호출한다.

구슬이 저장되어 있는 벡터의 길이가 2가 되었을 때의 합이 max보다 크다면 max를 업데이트.

*/

int N;
vector<int> v;
long long int max = 0;
long long int sum;

void getSum(int index, long long int sum, vector<int> v) {
	sum += v[index - 1] * v[index + 1];
	v.erase(v.begin() + index);

	if (v.size() == 2) {
		if (sum > ::max) ::max = sum;
		return;
	}

	for (int i = 1;i < v.size() - 1;i++) {		
		vector<int> v2 = v;
		getSum(i, sum, v2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--) {
		int W;
		cin >> W;
		v.push_back(W);
	}
	
	for (int i = 1;i < v.size() - 1;i++) {
		vector<int> v2 = v;
		getSum(i, 0, v2);
	}

	cout << ::max << endl;
}
