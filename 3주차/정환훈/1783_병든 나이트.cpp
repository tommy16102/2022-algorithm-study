#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈
    푼 날짜 : 2021/07/24

    기본 아이디어 : 모든 경우의 수 확인...
*/

int main() {

	int sero; int garo;
	cin >> sero >> garo;
	int answer = 0;
	if (sero == 1)
		answer = 1;
	if (sero == 2) { 
		if (garo == 1)
			answer = 1;
		if (garo == 2)
			answer = 1;
		if (garo == 3)
			answer = 2;
		if (garo == 4)
			answer = 2;
		if (garo == 5)
			answer = 3;
		if (garo == 6)
			answer = 3;
		if (garo >= 7)
			answer = 4;
	}
	if (sero >= 3) {
		if (garo == 1)
			answer = 1; //2=2 3=3 4=4
		if (garo == 2)
			answer = 2;
		if (garo == 3)
			answer = 3;
		if (garo == 4)
			answer = 4;
		if (garo == 5)
			answer = 4;
		if (garo == 6)
			answer = 4;

		if (garo >= 7) {
			answer = 5 + (garo - 7);
		}


	}

	cout << answer;

	return 0;
}
