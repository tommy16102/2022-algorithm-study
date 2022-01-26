#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

2022.1.26

기존 LCS로 배열에 문자열 길이 저장.
배열 내 우측 최하단부터 해당 길이와 같은 수가 위나 왼쪽에 없게 될 때까지 반복하여
해당 LCS의 길이부터 1까지 탐색.

*/

int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	
	s1 = " " + s1;
	s2 = " " + s2;
	for (int i = 0;i <= s1.length();i++) arr[0][i] = 0;
	for (int i = 0;i <= s2.length();i++) arr[i][0] = 0;

	for (int i = 1;i < s2.length();i++) {
		for (int j = 1;j < s1.length();j++) {
			if (s2[i] == s1[j]) arr[i][j] = arr[i - 1][j - 1] + 1;
			else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}

	int num = arr[s2.length() - 1][s1.length() - 1];
	cout << num << '\n';

	int sero = s2.length() - 1;
	int garo = s1.length() - 1;
	
	string ans;

	while (arr[sero][garo]) {
		if (arr[sero - 1][garo-1] == arr[sero][garo]) {
			sero--;
			garo--;
		}
		else if (arr[sero - 1][garo] == arr[sero][garo]) {
			sero--;
		}
		else if (arr[sero][garo - 1] == arr[sero][garo]) {
			garo--;
		}
		else {
			ans = s2[sero] + ans;
			sero--; garo--;
		}
	}
	cout<<ans<<'\n';
}
