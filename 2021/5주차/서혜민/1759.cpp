#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.08.09 서혜민

next_permutation이용해서 조합 생성 후 자음, 모음 개수 맞는 조합을 벡터에 넣은 후 정렬.

*/

int main() {
	int L, C;
	cin >> L >> C;

	string word = "";
	while (C--) {
		string s;
		cin >> s;
		word += s;
	}
	sort(word.begin(), word.end());
	vector<bool> v(word.size() - L, false);
	v.insert(v.end(), L, true);

	vector<string> res;
	do {
		string temp = "";
		for (int k = 0; k < word.size(); k++) {
			if (v[k]) temp += word[k];
		}
		int jcount = 0, mcount = 0;
		for (int k = 0;k < temp.size();k++) {
			if (temp[k] == 'a' || temp[k] == 'e' || temp[k] == 'i' || temp[k] == 'o' || temp[k] == 'u') mcount++;
			else jcount++;
		}
		if(jcount>=2 && mcount>=1) res.push_back(temp);
	} while (next_permutation(v.begin(), v.end()));

	sort(res.begin(), res.end());

	for (int i = 0;i < res.size();i++) {
		cout << res[i] << endl;
	}
}
