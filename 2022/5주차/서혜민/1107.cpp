#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

2022.2.14

N보다 낮은 채널에서 +누르는 경우 / N보다 높은 채널에서 -누르는 경우.

정답인 버튼을 누루는 횟수의 초기값(ans)은 현재 채널인 100과 N의 차이. 즉 abs(N-100)

N에서부터 하나씩 감소시켜가면서 해당 수가 고장나지 않은 버튼으로 만들 수 있는 지 확인.
해당 수가 만들 수 있는 수이면서 해당 수의 길이 + 해당 수와 N의 차이가 버튼을 누르는 횟수가 현재
ans보다 작으면 ans 업데이트.

N에서부터 하나씩 증가시켜가면서 해당 수가 고장나지 않은 버튼으로 만들 수 있는 지 확인.
해당 수가 만들 수 있는 수이면서 해당 수의 길이 + 해당 수와 N의 차이가 버튼을 누르는 횟수가 현재
ans보다 작으면 ans 업데이트.

*/

const int MAX = 9999999;
int N, M;
char buttons[10];

bool canMake(string num) {
	for (int i = 0;i < num.length();i++) {
		for (int j = 0;j < M;j++) {
			if (num[i] == buttons[j]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < M;i++) cin >> buttons[i];

	int now = 100;

	int ans = abs(N - now);

	int copyN = N;
	while (copyN >= 0) {
		string num = to_string(copyN);
		if (N - copyN + num.length() > ans) break;
		if (canMake(num)) {
			ans = min(ans, int(num.length()) + N - copyN);
			break;
		}
		copyN--;
	}

	copyN = N;
	while (copyN <= MAX) {
		string num = to_string(copyN);
		if (copyN - N + num.length() > ans) break;
		if (canMake(num)) {
			ans = num.length() + copyN - N;
			break;
		}
		copyN++;	
	}

	cout << ans << '\n';
}
