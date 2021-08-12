#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

2021.08.16 서혜민

재귀를 통해 부등호에 맞춰서 올 수 있는 숫자들을 넣어주면서
가장 큰 값, 가장 큰 수를 찾아냄.

*/

string max(10,'0');
string min(10, '9');
int k;
bool checked[10];
vector<char> v;

void makeNum(int num, string s, int count) {
	if (count == k) {
		if (s > ::max) ::max = s;
		if (s < ::min) ::min = s;
		return;
	}
	if (v[count] == '<') {
		for (int i = num + 1;i <= 9;i++) {
			if (!checked[i]) {
				checked[i] = 1;
				makeNum(i, s + to_string(i), count + 1);
				checked[i] = 0;
			}
		}
	}
	else if (v[count] == '>') {
		for (int i = 0;i < num;i++) {
			if (!checked[i]) {
				checked[i] = 1;
				makeNum(i, s + to_string(i), count + 1);
				checked[i] = 0;
			}
		}
	}
	else return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	
	for (int i = 0;i < k;i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}

	for (int i = 0;i <= 9;i++) {
		checked[i] = 1;
		makeNum(i, to_string(i), 0);
		checked[i] = 0;
	}

	cout << ::max << '\n' << ::min << '\n';
}
