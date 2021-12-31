#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

2021.12.31 서혜민

sort를 통해 정렬을 시켜서 접두어가 될 수 있는 단어가 앞에 나오도록 정렬을 한 뒤,
이중 for문을 통해서 다른 단어들의 접두어가 되는 단어의 개수를 구한 뒤, 전체 단어의 수에서 해당 개수를 뺀다.

*/

int main() {
	int N;
	cin >> N;

	vector<string> words;
	while (N--) {
		string s;
		cin >> s;
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	int count = 0;
	for (int i = 0;i < words.size(); i++) {
		string word = words[i];
		bool isStart = false;
		for (int j = i+1;j < words.size();j++) {
			if (words[j].find(word) == 0) isStart = true;
		}
		if (isStart) count++;
	}

	cout << words.size() - count << '\n';
}
