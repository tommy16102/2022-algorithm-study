#include <bits/stdc++.h>
using namespace std;

int t;
int a;
int b;

int v[10000];
bool isPrime(int x) {

	int lim = sqrt(x);
	for (int i = 2; i <= lim; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}


void input() {
	cin >> a >> b;
	
	for (int i = 1000; i <= 9999; i++) {
		v[i] = false;
	}
}

vector<string> next(int x, int mode) {

	// mode 0 - 첫째 1 - 둘째 2 - 셋째 3 - 넷째 바꿈
	string p = to_string(x);
	vector<string> xs;
	char c = p[mode];
	for (int i = 0; i < 10; i++) {
		if (i != c) { // 자기자신은 ㄴㄴ
			string temp = p;
			temp[mode] = i + '0';
			xs.push_back(temp);
		}
	}

	vector<int> ns;

	for (int i = 0; i < xs.size(); i++) {
		ns.push_back(stoi(xs[i]));
	}

	return xs;
}



void solve() {
	queue<int> q;
	q.push(a);
	v[a] = true;
	int time = -1;

	if (a == b) {
		cout << 0 << '\n';
		return;
	}

	while (!q.empty()) {
		
		int qsize = q.size();
		time++;
		for (int j = 0; j < qsize; j++) {
			int now = q.front();
			q.pop();
			for (int i = 0; i <= 3; i++) {
				vector<string> ns = next(now, i);
				for (int k = 0; k < ns.size(); k++) {
					int n = stoi(ns[k]);
					if (n >= 1000 && n <= 9999 && !v[n] && isPrime(n)) {
						v[n] = now;
						q.push(n);
					}
					if (n == b) {
						cout << time + 1 << '\n';
						return;
					}
				}
			}
		}
	}



	cout << "Impossible\n";
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		solve();
	}
	return 0;
}	