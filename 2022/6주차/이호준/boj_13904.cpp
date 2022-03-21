/*******************************************************************
Algorithm Study
Baekjoon OJ Priority Queue
13904 과제
2022/02/22 이호준
# 아이디어
1. Priority Queue로 풀어야하는 문제인지 처음에 알지 못했다 처음에 DP인줄 알았다.
효율적인 일 -> 스케쥴링 => Priority Queue (우선순위 알고리즘)

과제 마감일을 오름차순으로 정렬한다.
과제를 하나씩 priority queue에 넣으면서 queue의 size가 현재 확인하고 있는 works의 마감일 보다 작거나 같게 유지하면서
해당 과제를 수행하는 것이 더 좋을 지 판단한다.
이때, prioirty queue에 넣을 때 점수(즉, 보상)을 first로 넣어서 내림차순한다.
why? work에 들어간 순간 들어간 work는 문제없이 수행할 수 있고 그중에서 가장 작은 점술를 얻는 과제를 없애야 하므로.
항상 queue는 work보다 작거나 같게 유지되므로 queue에 들어가는 순간 모든 일이 진행될 수 있다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;


	vector<pair<int, int>> works(n, { 0,0 });

	for (int i = 0; i < n; i++) {
		cin >> works[i].first >> works[i].second;
	}

	sort(works.begin(), works.end());

	/*for (auto a : works) {
		cout << a.first << " " << a.second << "\n";
	}*/

	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> q;
	
	for (int i = 0; i < works.size(); i++) {
		if (q.empty() || q.size() < works[i].first) {
			q.push({ works[i].second, works[i].first });
		}
		else  if (q.size() == works[i].first) {
			if (works[i].second > q.top().first) {
				q.pop();
				q.push({ works[i].second, works[i].first });
			}
		}
	}

	int answer = 0;
	while (!q.empty()) {
		answer += q.top().first;
		q.pop();
	}

	cout << answer;

	return 0;
}