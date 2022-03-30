#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int oneCnt(int n) {
	bitset<25> bit(n);
	string s = bit.to_string();
	int cnt = 0;
	for (int i = 0;i < s.length();i++) if (s[i] == '1') cnt++;
	return cnt;
}

int main() {
	int N, K;
	cin >> N >> K;
	int n = N;
	while (1) {
		if (oneCnt(n) <= K) {
			cout << n - N;
			return 0;
		}
		else n++;
	}
}