#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
    푼 날짜 : 2021/08/07
    아이디어 : nCr의 조합을 만들어서 모든 경우의 수를 test, 성립하면 벡터에 집어넣기

*/

bool ismoeum(char c) { // 모음인지 판단하는 함수

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

bool test(string s) { // s가 조건에 맞는 문자열인지 판단하는 함수

	int moeum = 0; int jaeum = 0;

	for (int i = 0; i < s.size(); i++) { // 모음 자음 개수 세기
		if (ismoeum(s[i])) {
			moeum++;
		}
		else {
			jaeum++;
		}
	}

	if (moeum >= 1 && jaeum >= 2) { // 조건 1 : 모음 1 + 자음 2 이상
		char c = s[0];
		for (int i = 1; i < s.size(); i++) { // 조건 2 : 오름차순 배열
			if (c > s[i]) {
				return false;
			}
			else {
				c = s[i];
			}
		}

		return true;
	}

	else return false;

}



int main() {

	// 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음

	// input
	vector<char> chars;
	int l; int c;

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		chars.push_back(temp);
	}
	
	vector<int> temp;

	for (int i = 0; i < chars.size(); i++) {
		temp.push_back(1);
	}
	for (int i = 0; i < l; i++) {
		temp[i] = 0;
	}
	// input


	// 오름차순 정렬
	sort(chars.begin(), chars.end());


	//a t c i s w
	vector<string> result;


	do { // 조합으로 nCr 해서 해당 조합으로 나온 문자열 판단
		string s = "";
		for (int i = 0; i < chars.size(); i++) {
			if (temp[i] == 0) {
				s += chars[i];
			}
		}
		if (test(s)) {
			result.push_back(s);
		}
	} while (next_permutation(temp.begin(), temp.end()));

	//result.erase(unique(result.begin(), result.end()), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}



