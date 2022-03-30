/*******************************************************************
Algorithm Study
Baekjoon OJ DFS
1062 가르침
2022/03/30 이호준
# 아이디어
1. 문자를 아스키코드로 연산하고 bool visited를 통해 각 알파벳이 사용된 여부를 정하고
DFS를 수행해서 구한다.

bit masking 방식으로도 푸는 연습을 해야한다.
*******************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, k, result;
bool visit[26];
string s;
string word[50];

void dfs(char c, int cnt){
	if (cnt == k - 5){
		int sum = 0; // 읽을 수 있는 단어 개수
		for (int i = 0; i < n; i++){
			bool check = true; // 읽을 수 있는 단어인지
			for (int j = 0; j < word[i].size(); j++){
				if (!visit[word[i][j] - 'a']){
					check = false;
					break;
				}
			}
			if (check) sum++;
		}

		result = max(sum, result);
		return;
	}

	for (int i = c; i < 26; i++){
		if (!visit[i]){
			visit[i] = true;
			dfs(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;

	// anta, tica 짜르기
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		tmp.substr(4);
		tmp.erase(tmp.size() - 4, tmp.size());
		word[i] = tmp;
	}

	// 'a','n','t','i','c' 최소 5글자 이상은 알아야 함
	if (k < 5){
		cout << 0 << '\n';
		return 0;
	}

	// 'a','n','t','i','c' 해당 글자들은 알고 있으므로.
	visit['a' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;

	dfs(0, 0);

	cout << result << '\n';

	return 0;
}