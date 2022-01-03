#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.1.3 서혜민

이중 for문을 통해 입력받은 동전별로 해당 동전의 가치를 시작으로 k원이 될 때까지,
가짓수를 저장하는 counts 배열에서 해당 금액에서 현재 동전의 가치를 뺀 금액의 가짓수를 저장.

*/

int counts[10001];
int coin[100];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0;i < n;i++) cin >> coin[i];

	counts[0] = 1;
	for (int i = 0;i < n;i++) {
		int price = coin[i];
		for (int j = price;j <= k;j++) {
			counts[j] += counts[j - price];
		}
	}

	cout << counts[k] << '\n';
}
