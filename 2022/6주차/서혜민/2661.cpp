#include <iostream>
#include <string>
using namespace std;

/*

2022.2.21

올 수 있는 수들을 문자열로 저장한 addNum에서 하나씩 꺼내서 뒤에 붙여 새 숫자열을 만든 뒤,
substr을 이용해서 수열을 만든 뒤, 바로 그 수열 앞에 똑같은 길이의 수열을 확인해
두 개의 수열이 일치하면 나쁜 수열.

*/

int N;
string addNum[3] = { "1", "2", "3" };

void makeNum(string num) {
	if (num.length() == N) {
		cout << num;
		exit(0);
	}

	for (int i = 0;i < 3;i++) {
		string newNum = num + addNum[i];
		int len = newNum.length()/2;
		bool canMake = false;
		for (int j = 1;j <= len;j++) {
			int startIndex = newNum.length() - j;
			string part = newNum.substr(startIndex);
			int partL = part.length();
			string part2 = newNum.substr(startIndex - partL, partL);
			if (part == part2) {
				canMake = true;
				break;
			}
		}
		if (!canMake) makeNum(newNum);
	}
}

int main() {
	cin >> N;
	for (int i = 0;i < 3;i++) makeNum(addNum[i]);
}
