#include <iostream>
#include <string>
using namespace std;

/*
2021.12.30 서혜민

한 줄로 입력받은 문자열에서 먼저 공통부분 자료형과 변수부분들로 나눈 뒤,
변수부분들에서 쉼표를 기준으로 변수부분임을 판단하여, 해당 부분에서
알파벳이 아니면 공통부분 자료형에 해당 문자를 붙여주고,
알파벳이면 변수에 해당 문자를 붙여주는 방식으로 풀이.
*/

bool checkAp(char c) {
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

int main() {
	string line;
	getline(cin, line);
	
	int start = line.find(' ');
	string common = line.substr(0, start);
	string vars = line.substr(start+1);

	start = 0;
	bool finish = false;
	while (1) {
		int index = vars.find(',', start);
		if (index == -1) {
			index = vars.length()-1;
			finish = true;
		}
		string var;
		string toCommon;
		for (int i = start; i < index;i++) {
			if (checkAp(vars[i])) {
				var += vars[i];
			}
			else {
				if (vars[i] == '[' && vars[i + 1] == ']') {
					toCommon = "[]" + toCommon;
					i++;
				}
				else toCommon = vars[i] + toCommon;
			}
		}
		cout << common+toCommon << ' ' << var << ';' <<'\n';
		start = index + 2;
		if (finish) break;
	}
}
