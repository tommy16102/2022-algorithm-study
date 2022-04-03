/*******************************************************************
Algorithm Study
Baekjoon OJ 
1931 회의실 배정
2022/03/31 이호준
# 아이디어
1. 회의실을 가장 많이 사용할 수 있는 회의 사용표를 만들어 주어진 시간표 내에서 가장 많은
회의를 진행할 수 있는 최대 개수를 구하는 문제이다.

1. 먼저 든 생각은 회의시간이 짧은 것들을 잘 모으면 되지않을까?
=> 그런데 이 방법은 고려해야하는게 좀 많았다.

2. 그러면 결국 회의를 시작하려면 끝나야하는데 이 끝나는 시간이 먼저 끝나는 것으로 정렬해보고
회의가 진행될수 있는 경우들을 연결하면 되지않을까?
회의는 시작되서 끝나는 시간이 있을 때 끝나는 시간이 더 빨라야 더 많은 회의를 진행할 수 있는 경우가 많으므로
회의를 끝나는 시간으로 오름차순으로 정렬하고 회의가 끝나는 시간이 같다면 그중에 연결되는 하나를 선택하면된다.
회의가 끝나는 시간이 짧은것이 있고 그것이 연결이 된다면 그것을 카운트하면 된다.

결국, 회의가 끝나는 시간을 기준으로 생각해서 같은 시간내 더 많은 강의를 넣을 수 있는 현재의 최선을 선택하면 되는 문제였다.
뒤에 더 좋은 경우가 있을 수 있다는 것은 지금 생각할 필요없다.
처음부터 끝나는 시간이 가장 빠른 회의를 선택해 왔기 때문에, 현재에서 최선의 경우를 고르게만 된다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	int n;

	cin >> n;

	vector<pair<int, int>> input;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		input.push_back({y,x});
	}

	sort(input.begin(), input.end());

	int answer = 1;
	int end_time = input[0].first;

	for (int i = 1; i < n; i++) {
		if (end_time <= input[i].second) {
			end_time = input[i].first;
			answer++;
		}
	}

	cout << answer;


	return 0;
}