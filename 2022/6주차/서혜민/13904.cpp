#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*

2022.2.20

마감일이 빠른 것부터 해당 마감일에 맞출 수 있는 과제들 중 점수가 높은 것들을 처리하게 되면,
점수가 높지만 마감일에 못맞춰서 생략을 하게되는 과제가 생기게된다.

그래서, 마감일이 늦는 것부터, 해당 마감일에 맞출 수 있는 과제들 중,
점수가 가장 높은 것들을 처리해나간다.
이렇게 뒤에서부터 처리해나가면 생략 없이 최대값을 구할 수 있게된다.

*/

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	int day = 0;

	for (int i = 0;i < N;i++) {
		int d, w;
		cin >> d >> w;
		v[i] = { d,w };
		if (d > day) day = d;
	}

	sort(v.begin(), v.end(), greater<>());

	priority_queue<pair<int, int>> queue;
	int sum = 0;

	while (day) {
		for (int i = 0;i < v.size();i++) {
			if (v[i].first >= day) {
				queue.push({ v[i].second, i });
			}
		}
		if (!queue.empty()) {
			sum += queue.top().first;
			v[queue.top().second].first = 0;
		}
		while (!queue.empty()) queue.pop();
		day--;
	}

	cout << sum;
}
