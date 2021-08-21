#include <iostream>
#include <queue>
using namespace std;

/*

2021.08.23 
오름차순, 내림차순 pq 2개를 이용한 문제
입력된 수는 오름차순의 top을 기준으로 그것보다 크면 오름차순 pq.
작으면 내림차순 pq에 들어가게 된다.
오름차순의 top이 항상 중간 수를 유지하기 위해서 입력을 받은 후,
입력받은 수의 개수가 짝수일 때는 이 두개의 pq의 크기가 같을 때,
홀수일 때는 오름차순의 pq의 크기가 내림차순의 pq의 크기보다 1 같을 때의 오름차순의 top이
중간수가 되므로 크기가 많은 큐에서 작은 큐로 이동을 시켜줘야한다.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	
	int m;
	priority_queue<int> pq1;
	priority_queue<int,vector<int>,greater<int>> pq2;
	
	for (int i = 1;i <= N;i++) {
		cin >> m;
		if (i==1) pq1.push(m);
		else if (m > pq1.top()) pq2.push(m);
		else if (m <= pq1.top()) pq1.push(m);

		if (pq1.size() < pq2.size()) {
			while (pq2.size() > pq1.size()) {
				pq1.push(pq2.top());
				pq2.pop();
			}
		}
		else if(pq1.size()-1>pq2.size()){
			while (pq1.size() > pq2.size()) {
				pq2.push(pq1.top());
				pq1.pop();
			}
		}
		cout << pq1.top() << '\n';
	}
}
