/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
1094 막대기
2022/02/22 이호준
# 아이디어
1. 비트마스킹
*******************************************************************/
#include <iostream>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int x, answer = 0; 
	cin >> x;
	for (int i = 0; i < 7; i++) {
		if (x & (1 << i)) answer++;
		//cout << (1 << i ) << endl;
		//cout << (x & (1 << i)) << endl;
	}
	cout << answer;

	return 0;
}

//while x > 0 {
//	// 맨 마지막 비트가 꺼짐
//	x &= (x - 1)
//		answer += 1
//}