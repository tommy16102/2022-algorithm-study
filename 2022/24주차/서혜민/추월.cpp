#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> V(N);
	for (int i = 0; i < N; i++) {
		string num;
		cin >> num;
		m[num] = i;
	}
	
	for (int i = 0; i < N; i++) cin >> V[i];
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int now = m[V[i]];
		for (int j = i + 1; j < N; j++) {
			if (m[V[j]] < now) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}
