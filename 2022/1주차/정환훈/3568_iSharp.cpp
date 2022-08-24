#include <bits/stdc++.h>
using namespace std;

string s;

void input() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	getline(cin, s);
}

void solve() {

	int first_space = s.find(' '); // 첫 공백 등장 인덱스
	string basic_type = s.substr(0, first_space); // 공통타입부분 문자열

	string vars = s.substr(first_space + 1); // 변수들 string

	vector<string> var_names; // 각각의 변수 이름
	vector<string> var_types; // 각각의 추가 변수 타입

	string name_temp = "";
	string type_temp = "";

	for (int i = 0; i < vars.size(); i++) {
		if (vars[i] == ',' || vars[i] == ';') { // ',' 나 ';' 등장시 담고 있는 name과 type을 push 후 진행
			var_names.push_back(name_temp);
			var_types.push_back(type_temp);
			continue;
		}
		else if (vars[i] == ' ') { // ' '등장 시 name, type 초기화 후 진행
			name_temp = "";
			type_temp = "";
			continue;
		}

		if (isalpha(vars[i])) { // 변수명일 시
			name_temp += vars[i];
		}
		else { // 타입명일 시
			type_temp += vars[i];
		}
	}



	for (int i = 0; i < var_types.size(); i++) { // 뒤집어주는 과정
		reverse(var_types[i].begin(), var_types[i].end());
	}

	for (int i = 0; i < var_types.size(); i++) { // 뒤집어서 "]["가 된 부분을 "[]"로 고쳐주는 과정
		for (int j = 0; j < var_types[i].size(); j++) {
			if (var_types[i][j] == '[')
				var_types[i][j] = ']';
			else if (var_types[i][j] == ']')
				var_types[i][j] = '[';
		}
	}

	for (int i = 0; i < var_names.size(); i++) { // 결과 출력
		cout << basic_type << var_types[i] << " " << var_names[i] << ";\n";
	}
}

int main(void) {

	input();
	solve();
}