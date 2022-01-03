#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	푼 사람 : 정환훈
    푼 날짜 : 2021/07/25

    기본 아이디어 : 1은 특별취급으로 그냥 더해주고 양수음수0으로 나눠서 벡터 넣음
	양수 음수
    홀 홀
    양수 큰수대로 묶고
    음수 큰수대로 묶고 남은 찌꺼기들 더하거나 곱하기

    홀 짝
    양수 큰수대로 묶고
    음수 큰수대로 묶고 남은 양수 하나 더하기

    짝 홀
    양수 큰수대로 묶고
    음수 큰수대로 묶고 남은 음수 하나 더하기


    짝 짝
    양수 큰수대로 묶고
    음수 큰수대로 묶기

*/

int main() {
	int sum = 0;

	int n1 = 0; int n2 = 0;
	int N;
	vector<int> plus;
	vector<int> minus;
	vector<int> zero;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0) {
			if (temp == 1){
				sum++;
			}
			else
			plus.push_back(temp);
		}
		else if (temp < 0)
			minus.push_back(temp);
		else zero.push_back(temp);

	}

	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	if (plus.size() % 2 == 0 && minus.size() % 2 == 0) { // 짝짝

		for (int i = 0; i < plus.size(); i += 2) { // 8 01 23 45 67
			n1 = plus[i]; n2 = plus[i + 1];
			sum += n1 * n2;
		}
		for (int i = 0; i < minus.size(); i += 2) {
			n1 = minus[i]; n2 = minus[i + 1];
			sum += n1 * n2;
		}

	}

	else if (plus.size() % 2 != 0 && minus.size() % 2 != 0) { // 홀홀

		// 3 2 1 -3 -2 -1
		for (int i = 0; i < plus.size() - 1; i += 2) { // 7 01 23 45
			n1 = plus[i]; n2 = plus[i + 1];
			sum += n1 * n2;
		}
		int plus_res = plus[plus.size() - 1];
		for (int i = 0; i < minus.size() - 1; i += 2) {
			n1 = minus[i]; n2 = minus[i + 1];
			sum += n1 * n2;
		}
		int minus_res = minus[minus.size() - 1];

		if (!zero.empty()) {
			sum += plus_res;
		}

		else if (minus_res + plus_res > plus_res * minus_res) {
			sum += minus_res + plus_res;
		}
		else {
			sum += minus_res * plus_res;
		}


	}

	else if (plus.size() % 2 != 0 && minus.size() % 2 == 0) { // 홀짝
		for (int i = 0; i < plus.size() - 1; i += 2) { // 7 01 23 45
			n1 = plus[i]; n2 = plus[i + 1];
			sum += n1 * n2;
		}
		int plus_res = plus[plus.size() - 1];

		for (int i = 0; i < minus.size(); i += 2) {
			n1 = minus[i]; n2 = minus[i + 1];
			sum += n1 * n2;
		}


		sum += plus_res;
	}


	else if (plus.size() % 2 == 0 && minus.size() % 2 != 0) { // 짝홀
		for (int i = 0; i < plus.size(); i += 2) { // 8 01 23 45 67
			n1 = plus[i]; n2 = plus[i + 1];
			sum += n1 * n2;
		}

		for (int i = 0; i < minus.size() - 1; i += 2) {
			n1 = minus[i]; n2 = minus[i + 1];
			sum += n1 * n2;
		}
		int minus_res = minus[minus.size() - 1];

		if (!zero.empty()) {

		}
		else {
			sum += minus_res;
		}
	}

	cout << sum;


}