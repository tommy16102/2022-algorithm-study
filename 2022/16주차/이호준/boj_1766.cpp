/*******************************************************************
Algorithm Study
Baekjoon OJ 위상정렬
1766 문제집
2022/07/06 이호준
# 아이디어
1. 먼저 수행해야하는 순서가 존재 -> 위상정렬
2. 가능한 낮은 순서부터 스케쥴링 -> Priority Queue

맨 처음 풀이때 그냥 while문으로 반복을 진행했다.
통과했지만 속도가 느렸는데 생각해보니 priority queue에 넣으면 되는 문제였다.
스케쥴링을 할때 PQ를 항상 먼저 떠올려봐야한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int possible[32001];
vector<int> info[32001];

//int main(void) {
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	int num_total_problems, num_infos;
//
//	cin >> num_total_problems >> num_infos;
//	
//
//	for (int i = 0; i < num_infos; i++) {
//		int first, next;
//		cin >> first >> next;
//		info[first].push_back(next);
//		possible[next]++;
//	}
//
//	int solve_problem = 0;
//	int first_check_index = 1;
//	while (1) {
//		if (solve_problem == num_total_problems) {
//			break;
//		}
//		for (int i = first_check_index; i <= num_total_problems; i++) {
//			if (possible[i] == 0) {
//				cout << i << " ";
//				possible[i] = -1;
//				bool ischange = false;
//				for (auto a : info[i]) {
//					possible[a]--;
//					ischange = true;
//				}
//				if (i == first_check_index) {
//					first_check_index++;
//				}
//				solve_problem++;
//				if (ischange) {
//					break;
//				}
//			}
//		}
//	}
//
//	return 0;
//}

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num_total_problems, num_infos;

	cin >> num_total_problems >> num_infos;


	for (int i = 0; i < num_infos; i++) {
		int first, next;
		cin >> first >> next;
		info[first].push_back(next);
		possible[next]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= num_total_problems; i++){
		if (possible[i] == 0) pq.push(i);
	}
	while (!pq.empty()){
		int current = pq.top(); 
		pq.pop();
		cout << current << ' ';
		for (auto check : info[current]){
			if (--possible[check] == 0){
				pq.push(check);
			}
		}
	}

	return 0;
}