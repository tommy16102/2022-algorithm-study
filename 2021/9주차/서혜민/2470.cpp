#include <iostream>
#include <algorithm>
#include <vector>]
#include <cstdlib>
#include <limits.h>
using namespace std;

/*

2021.09.04 서혜민

front, back이라는 두 개의 포인터를 둬서 해당 두 인덱스의 합의 절대값이 min보다 작다면
min에 넣어주고 그렇지 않고 합이 양수이면 0에 가까운 값을 만들기 위해 더 그 수보다 작은 수를 더해야하므로 back을 한칸 앞당기고, 
0보다 작다면 더 큰 수를 더해야하므로 front를 한칸 앞당긴다.

*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0;i < N;i++) cin >> v[i];

	sort(v.begin(), v.end());

	int front = 0, back = N - 1;
	int minsum = INT_MAX;
	int x, y;
	while (front < back) {
		int sum = v[front] + v[back];
		if (abs(sum) < minsum) {
			minsum = abs(sum);
			x = front;
			y = back;
		}
		else {
			if (sum > 0) back--;
			else front++;
		}
	}
	cout << v[x] << ' ' << v[y] << endl;
}