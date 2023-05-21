/*******************************************************************
Algorithm Study
Baekjoon 2608 로마숫자
2023/05/19 이호준
# 아이디어
1. 문자열조작과 구현
*******************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dictionary{
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};

int romToNumber(string rom) {
	int len = rom.length();
	int ans = 0;
	for(int i = 0; i < len; i++) {
		if(i + 1 != len && dictionary[rom[i]] < dictionary[rom[i + 1]]) {
			ans -= dictionary[rom[i]];
		} else {
			ans += dictionary[rom[i]];
		}
	}
	return ans;
}

int main(void){

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	int sum = romToNumber(s1) + romToNumber(s2);
	cout << sum <<"\n";

	while (sum > 0)
	{
		if (sum >= 1000)
			cout << "M", sum -= 1000;
		else if (sum >= 900)
			cout << "CM", sum -= 900;
		else if (sum >= 500)
			cout << "D", sum -= 500;
		else if (sum >= 400)
			cout << "CD", sum -= 400;
		else if (sum >= 100)
			cout << "C", sum -= 100;
		else if (sum >= 90)
			cout << "XC", sum -= 90;
		else if (sum >= 50)
			cout << "L", sum -= 50;
		else if (sum >= 40)
			cout << "XL", sum -= 40;
		else if (sum >= 10)
			cout << "X", sum -= 10;
		else if (sum >= 9)
			cout << "IX", sum -= 9;
		else if (sum >= 5)
			cout << "V", sum -= 5;
		else if (sum >= 4)
			cout << "IV", sum -= 4;
		else
			cout << "I", sum -= 1;
	}

	return 0;
}