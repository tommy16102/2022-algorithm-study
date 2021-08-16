#include <iostream>
#include <string>
#include <map>
using namespace std;

/*

2021.08.23 서혜민

map을 통해 이름과 출/퇴근 여부를 입력받은 뒤, 이 둘을 key-value로서 map에 삽입해주면 된다.
key는 중복이 안되므로, 해당 key의 value가 leave로 덮어씌워지지 않은 key만 뒤에서부터 출력한다.

*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	map<string, string> map;
	string s, log;
	for (int i = 0;i < n;i++) {
		cin >> s >> log;
		map[s] = log;
	}

	for (auto it = map.rbegin();it != map.rend();it++) {
		if (it->second != "leave") cout << it->first <<'\n';
	}
}
