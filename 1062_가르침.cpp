#include <bits/stdc++.h>
using namespace std;

int n; int k;
vector<string> words;
bool know[26];
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		word = word.substr(4); // no anta
		word = word.substr(0, word.size() - 4); // no tica
		words.push_back(word);
	}	
}


void solve() {

	// anta tica
	// 26Ck

	if (k >= 26) { // 모든 문자 다 배우면 다 읽겠지
		cout << n;
		return;
	}
	int learn = k - 5; // 기본 소양 빼고 몇개 더 배울지

	if (learn < 0) {
		cout << 0;
		return;
	}

	vector<int> index(26, 0);
	// 26Ck-5
	


	for (int i = 0; i < learn; i++) {
		index[25 - i] = 1;
	}

	int m = 0;

	do {

		bool bye = false;
		for (int i = 0; i < 26; i++) {
			if (index[i]) {
				if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a') { // 기본 소양에 중복된거 배움
					bye = true;
					break;
				}

				know[i] = true;
			}
			else
				know[i] = false;
		}
		if (bye) // 넘어가기
			continue;

		// 기본 소양들은 알고 있으니까
		know['a' - 'a'] = true;
		know['n' - 'a'] = true;
		know['t' - 'a'] = true;
		know['i' - 'a'] = true;
		know['c' - 'a'] = true;
		
		int mtest = 0;
		for (int i = 0; i < words.size(); i++) {
			bool can = true;
			for (int j = 0; j < words[i].size(); j++) {
				if (know[abs('a' - words[i][j])] == false) { // 모르는거 있음
					can = false;
					break;
				}
			}
			if (can) // 다 아는거임
				mtest++;
		}

		m = max(mtest, m);
	} while (next_permutation(index.begin(), index.end()));

	cout << m;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}