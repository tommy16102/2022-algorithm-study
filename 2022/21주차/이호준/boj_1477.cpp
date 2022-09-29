/*******************************************************************
Algorithm Study
BAEKJOON 21주차
1477 휴가소 세우기
2022/09/29 이호준
# 아이디어
1. 이분탐색
*******************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, l;
vector <int> vec;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> l;
	int temp;
	vec.push_back(0), vec.push_back(l); 
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	int low = 1, high = l;
	int mid, result = 0;

	while (low <= high) {
		mid = (low + high) / 2; 

		int val = 0; // 휴게소 사이에 배치 될 수있는 휴게소의 갯수
		for (int i = 1; i < vec.size(); i++) {
			int dist = vec[i] - vec[i - 1]; 

			val += (dist / mid); // 휴게소 간격 / 현재 길이
			if (dist%mid == 0) //휴게소가 이미 있는 위치라면 
				val--; 
		}
		if (val > m)  
			low = mid + 1; 
		else {
			high = mid - 1; 
			result = mid;  
		}
	}

	cout << result << endl;

	return 0;
}