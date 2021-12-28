#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

/*

2021.08.02 서혜민

최대값을 구할 때와 다른점은
1) max대신 min을 사용
2) 최소인 값을 찾아야하므로 초기의 ans[0]만 0으로 지정해놓고, ans 배열 내
그 이외의 값은 전부 나올 수 있는 값이 1000*10000이하이므로 1000*10000+1로 설정.

*/

int arr[1001] = { 0, };
int ans[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(ans, 1001, 10000001);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	ans[0] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			ans[j] = min(ans[j], ans[j - i] + arr[i]);
		}
	}
	cout << ans[n] << endl;
}
