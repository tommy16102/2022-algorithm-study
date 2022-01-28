#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

/*

2022.1.28

DP.

어떠한 금액을 만드는 방법의 수는 특정 동전을 기준으로 해서
그 동전의 금액을 뺀 금액을 만드는 방법의 수와 기존의 동전의 금액을 더한 총 금액의 방법의 수에
더했을 때의 방법의 수와 더하지 않은 총 금액의 방법의 수를 비교하여 더 큰 방법의 수를 저장해나가는 과정.

*/

int coin[21];
int kinds[10001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		for (int i = 1;i <= N;i++) cin >> coin[i];
		cin >> M;

		
		for (int i = 1;i <= N;i++) {
			int cost = coin[i];
			kinds[cost]++;
			for (int j = cost;j <= M;j++) {
				kinds[j] = max(kinds[j], kinds[j] + kinds[j - cost]);
			}
		}
		cout << kinds[M] << '\n';

		memset(coin, 0, sizeof(coin));
		memset(kinds, 0, sizeof(kinds));
	}
}
