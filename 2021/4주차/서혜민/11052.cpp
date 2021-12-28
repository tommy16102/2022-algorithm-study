#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.08.02 서혜민

1부터 n장까지 있는 카드팩을 반복문을 통해
1장 짜리 카드팩부터 n장까지 만드는 데 드는 비용을 ans배열에 저장을 하는데,
기존 ans[j]의 값과 ans[j-i]+costs[i]를 비교하여 더 큰 값을 저장한다.

ex) n=4  1,5,6,7
1 2 3 4
1 5 6 10
1 5 6 10
1 5 6 10

*/
int costs[10001] = { 0, };
int ans[10001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> costs[i];
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			ans[j] = max(ans[j], ans[j - i] + costs[i]);
		}
	}

	cout << ans[n] << endl;
}