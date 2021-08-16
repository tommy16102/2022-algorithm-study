#include <iostream>
#include <string>
#include <map>
using namespace std;

/*

2021.08.23 서혜민

map 내 키 존재 x ->1, 이미 존재 ->2

*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<string, int> map;

	int N, M;
	cin >> N >> M;
	string name;
	int count = 0;
	for (int i = 0;i < N + M;i++) {
		cin >> name;
		if (map.find(name) != map.end()) {
			map[name]=map[name] + 1;
		}
		else map[name]=1;
		if (map[name] == 2) count++;
	}
	cout << count << '\n';
	for (auto it = map.begin();it != map.end();it++) {
		if (it->second == 2)cout << it->first << endl;
	}
}
