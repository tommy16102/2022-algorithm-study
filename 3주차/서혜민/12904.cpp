#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

2021.07.24 서혜민

t를 계속 변환을 해서 s로 만들 수 있는지 확인하는 방법이다.

t의 맨 마지막 문자가 A일 때는, t를 A가 나온 바로 이전까지 잘라주고
맨 마지막 문자가 B일 때는 B가 나온 바로 이전까지 잘라준 뒤,
reverse를 통해 문자열을 뒤집어준다.

이렇게 변환을 진행하면서 s와 같게 되면 1을 출력하지만,
t의 길이가 0이 될때까지 s와 같게 되지 않는다면 0을 출력한다.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	cin >> s >> t;
	while (1) {
		if (t[t.length() - 1] == 'A') {
			t = t.substr(0, t.length()-1);
		}
		else {
			t = t.substr(0, t.length()-1);
			reverse(t.begin(), t.end());
		}
		if (t == s) {
			cout << 1 << endl;
			return 0;
		}
		if (t.length() == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
}