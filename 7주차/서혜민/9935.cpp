#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

2021.08.23 서혜민

answer라는 문자열을 둬서, 입력받은 전체 문자열의 앞에서부터 하나씩 차례대로 넣는데,
입력받은 폭발 문자열의 마지막에 오는 문자를 넣게 되면, 그 문자를 기준으로, 폭발 문자열의 길이의 수만큼
앞으로 한칸씩 이동하면서 answer의 문자와 폭발문자열의 문자를 같은지 비교를 해서, 폭발 문자열의 길이만큼
그 수가 같다면 해당 문자열은 폭발시키므로 answer에서 pop_back을 통해서 없애준다.

이 과정을 문자열의 끝까지 탐색할 때까지 반복을 하는 데,
폭발을 계속하게 되면 asnwer에는 남는 문자열이 없으므로 FRULA를 출력시키면 된다.

*/

bool checked[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string before;
	string part;
	cin >> before >> part;

	string answer = "";

	for (int i = 0;i < before.length();i++) {
		answer += before[i];
		if (answer[answer.length()-1] == part[part.length() - 1] && answer.length()>=part.length()) {			
			int count = 0;
			for (int j = part.length() - 1;j >= 0;j--) {
				if (part[j] == answer[answer.length() - (part.length() - j)]) count++;
			}
			if (count == part.length()) {
				for (int j = 0;j < part.length();j++) {
					answer.pop_back();
				}
			}
		}
	}

	if (answer == "") cout << "FRULA" << endl;
	else cout << answer << endl;
}
