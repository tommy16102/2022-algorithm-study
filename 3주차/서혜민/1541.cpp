#include <iostream>
#include <string>
using namespace std;

/*

2021.07.26 서혜민

값이 최소가 나오도록 하려면 -부호가 시작되는 부분에서 괄호를 시작하는데,
괄호 안에서 -부호를 만나면 +부호가 되므로 -부호 전에 괄호를 닫는 방식이다.

이 방식은 -부호가 나오기 전까지는 항상 부호에 맞춰서 값을 더했지만, 
-부호가 나온 뒤부터는 +부호가 나와도 모든 값을 빼줌을 통해 구현할 수 있다.

*/


int main() {
	string s;
	cin >> s;

	int sum = 0;
	string num = "";
	
	bool plus = 1;
	bool minus = 0;
	for (int i = 0;i < s.length();i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			num += s[i];
		}
		else {
			if (minus) sum -= stoi(num);
			else sum += stoi(num);
			if (s[i] == '-') minus = 1;
			num = "";
		}
	}
	if (minus) sum -= stoi(num);
	else sum += stoi(num);
	cout << sum << endl;
}