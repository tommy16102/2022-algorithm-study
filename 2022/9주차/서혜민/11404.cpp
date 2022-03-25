#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000 * 100 + 1;
int arr[101][101];

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			arr[i][j] = MAX;
			if (i == j) arr[i][j] = 0;
		}
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (arr[i][j] == MAX) arr[i][j] = 0;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}