#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M, K;
string arr[1001];

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> K;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') cnt++;
		}
		int sum = 0;
		if (cnt <= K && cnt % 2 == K % 2) {
			for (int j = 0; j < N; j++) {
				if (arr[i] == arr[j]) sum++;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
}
