#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈
    푼 날짜 : 2021/07/23

    기본 아이디어 : 주어진 식을 숫자, 기호로 parse 한 다음
    -만나기 전까지는 다 더하고 -처음 만난 후에는 다 뺀다
    근데 이게 왜 그리디?

*/

int main() {

	string expression;

	cin >> expression;

	vector<string> parsed;
	string temp = "";

	for (int i = 0; i < expression.size(); i++) { // 1+234+56+032-42
		if (expression[i] == '-') {
			if (temp != "") {
				parsed.push_back(temp);
				temp = "";
			}
			parsed.push_back("-");
		}
		else if (expression[i] == '+') {
			if (temp != "") {
				parsed.push_back(temp);
				temp = "";
			}
			parsed.push_back("+");
		}
		else {
			temp += expression[i];

		}
	}

	parsed.push_back(temp);

	for (int i = 0; i < parsed.size(); i++) {
		int j = 0;
		while (parsed[i].at(j) == '0') {
			j++;
		}
		parsed[i] = parsed[i].substr(j);
	}

	int sum = 0;
	char operation = '+';
	int id = 0;
	while (operation == '+' && id < parsed.size()) {

		if (parsed[id] == "+") {
			id++;
			continue;
		}

		if (parsed[id] == "-") {
			id++;
			break;
		}

		else {
			sum += stoi(parsed[id]);
			id++;
		}		
	}

	for (int i = id; i < parsed.size(); i++) {
		if (parsed[i] != "+" && parsed[i] != "-") {
			sum -= stoi(parsed[i]);
		}
	}


	cout << sum << endl;
	return 0;
}