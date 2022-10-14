#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> C(N);
	for (int i = 0; i < N; i++) cin >> C[i];

	int M;
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++) cin >> B[i];

	sort(C.begin(), C.end(), greater<>());
	sort(B.begin(), B.end(), greater<>());

	int ans = 0;

	if (C[0] < B[0]) ans = -1;
	else {
		while (!B.empty()) {
			for (int i = 0; i < C.size(); i++) {
				for (int j = 0; j < B.size(); j++) {
					if (C[i] >= B[j]) {
						B.erase(B.begin() + j);
						break;
					}
				}
			}
			ans++;
		}
	}

	cout << ans;

}
