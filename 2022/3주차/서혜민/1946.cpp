#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> v;
		while (N--) {
			int s, m;
			cin >> s >> m;
			v.push_back({ s,m });
		}
		sort(v.begin(), v.end());
		int count = 0;
		int min = 100001;
		for (int i = 0;i < v.size();i++) {
			if (v[i].second < min) {
				count++;
				min = v[i].second;
			}
		}
		cout << count << '\n';
	}
}
