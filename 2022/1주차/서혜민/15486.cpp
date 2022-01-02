#include <iostream>
#include <algorithm>
using namespace std;

/*
2022.1.2 서혜민

for문을 통해 누적되는 최대 지급 금액을 저장하는 sum 배열 내 소요되는 일 수를
더한 일의 기존의 값과 누적된 금액에 해당 일에 지급받는 금액을 더했을 때의 값을 
비교를 하여 더 큰 값을 sum 배열에 저장을 하며, 누적되는 최대 금액을 저장한다.
*/

int T[1500000];
int P[1500000];
int sum[1500000];

int main() {
	int N;
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> T[i] >> P[i];
	}
	
	for (int i = 1;i <= N;i++) {
		sum[i + T[i]] = max(sum[i + T[i]], sum[i] + P[i]);
		sum[i + 1] = max(sum[i + 1], sum[i]);
	}

	cout << sum[N+1] << '\n';
}
