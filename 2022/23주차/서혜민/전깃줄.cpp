#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> V;
int arr[101];

int main() {
	int N;
	cin >> N;

	int m, n;
	for (int i = 0; i < N; i++) {
		cin >> m >> n;
		V.push_back({ m, n });
	}
	sort(V.begin(), V.end());

	int cnt = 0;

	for (int i = 0; i < V.size(); i++) {
		arr[i] = 1;
		for (int j = 0; j < i; j++) {
			if (V[j].second < V[i].second) {
				arr[i] = max(arr[i], arr[j] + 1);
			}
		}
		cnt = max(cnt, arr[i]);
	}

	cout << N - cnt;
}
