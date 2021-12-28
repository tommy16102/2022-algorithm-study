#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
시계방향으로 읽었을 때 가장 작은 수를 시계 수를 설정한 뒤,
1111부터 해당 시계수까지 시계수인 조건을 확인하는 check함수를 통해 시계수면 정답인 ans에 1을 더해주는 과정
*/

bool check(int num) {
	string  s = to_string(num);

	for (int i = 0;i < s.length();i++) {
		if (s[i] == '0') return false;
	}

	int s1 = stoi(s.substr(1) + s[0]);
	int s2 = stoi(s.substr(2) + s.substr(0,2));
	int s3 = stoi(s.substr(3) + s.substr(0,3));

	int minNum = min(num, min(s1, min(s2, s3)));

	if (num == minNum) return true;
	else return false;
}

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int s1 = stoi(a + b + c + d);
	int s2 = stoi(b + c + d + a);
	int s3 = stoi(c + d + a + b);
	int s4 = stoi(d + a + b + c);

	int num = min(s1, min(s2, min(s3, s4)));
	
	int start = 1111;
	int ans = 1;
	while (1) {
		if (start == num) break;
		if (check(start)) ans++;
		start++;
	}

	cout << ans << endl;
}
