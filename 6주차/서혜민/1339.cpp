#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*

2021.08.10 서혜민

입력받은 문자열에서 알파벳과 해당 자릿수를 추출하여 이 쌍을 원소로 가지는 벡터에 넣어준다.
이미 벡터에 존재하는 알파벳이라면 그 알파벳을 찾아서 자리수만 바꿔준다.

벡터에 모두 삽입이 끝나면 벡터의 두번째 요소인 자릿수의 합을 내림차순으로 정렬한다.

이후 앞에서부터 9를 시작으로 하나씩 감소시키면서 이 자릿수의 합을 곱해주면된다.

*/

vector<pair<char, int>> v;
bool compare(pair<char, int> m, pair<char, int> n) {
	return m.second > n.second;
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		for (int i = 0;i < s.length();i++) {
			char alpha = s[i];
			int ten = pow(10, s.length() - i - 1);
			
			int j=-1;
			for (j = 0;j < v.size();j++) {
				if (v[j].first == alpha) break;
			}
			if (j == v.size()) {
				v.push_back({ alpha, ten });
			}
			else v[j].second += ten;
		}
	}
	sort(v.begin(), v.end(), compare);

	int sum = 0;
	int num = 9;
	for (int i = 0;i < v.size();i++) {
		sum += v[i].second * num--;
	}

	cout << sum << endl;
}
