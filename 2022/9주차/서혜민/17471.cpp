#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX 100*10+1
using namespace std;

int arr[11][11];
bool visited[11];
int ans = MAX;

int main() {
	int N;
	cin >> N;

	int sum = 0;

	vector<int> v(N);
	for (int i = 0;i < N;i++) {
		cin >> v[i];
		sum += v[i];
	}

	for (int i = 1;i <=N;i++) {
		int n;
		cin >> n;
		while (n--) {
			int m;
			cin >> m;
			arr[i][m] = 1;
			arr[m][i] = 1;
		}
	}

	for (int i = 1;i <= (1 << N)-1;i++) {
		bitset<10> bs(i);
		string s = bs.to_string().substr(10-N);
		int sum0 = 0, sum1 = 0;
		bool canZero = false, canOne = false;
		memset(visited, 0, sizeof(visited));
		for (int j = 0;j < s.length();j++) {
			if (canZero && canOne) break;
			queue<int> queue;
			if (!canZero && s[j] == '0') {
				queue.push(j + 1);
				visited[j + 1] = 1;
				canZero = true;
				while (!queue.empty()) {
					int now = queue.front();
					sum0 += v[now - 1];
					queue.pop();
					for (int k = 1;k <= N;k++) {
						if (arr[now][k] == 1 && !visited[k] && s[k-1]=='0') {
							visited[k] = 1;
							queue.push(k);
						}
							
					}
				}
			}
			else if (!canOne && s[j] == '1') {
				queue.push(j + 1);
				visited[j + 1] = 1;
				canOne = true;
				while (!queue.empty()) {
					int now = queue.front();
					sum1 += v[now - 1];
					queue.pop();
					for (int k = 1;k <= N;k++) {
						if (arr[now][k] == 1 && !visited[k] && s[k-1]=='1') {
							visited[k] = 1;
							queue.push(k);
						}

					}
				}
			}
		}
		if (sum == sum0 + sum1) {
			ans = min(ans, abs(sum0 - sum1));
		}
	}
	if (ans == MAX) ans = -1;
	cout << ans;
}