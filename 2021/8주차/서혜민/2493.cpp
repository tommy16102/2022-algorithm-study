#include <iostream>
#include <stack>
using namespace std;

/*

2021.09.03 서혜민

숫자가 몇번째로 입력되었는지를 나타내는 인덱스와 값을 쌍으로서 가지는 스택에서
처음에 스택이 비어있다면 단순히 그때의 인덱스인 0과 값을 넣어준 뒤, 그 다음부터
해당 입력받은 수가 스택의 최상위의 숫자(두번째 인자 second)보다 크다면 좌향으로 발사하는 레이저를 송신할 수 있는 
그 수보다 큰 수를 만나고 스택이 비어있지 않을 때까지 스택에서 pop을 시킨다.
while문을 빠져나왔을 때 스택이 비어있다면, 더 높은 탑은 없는 것이므로, 0을 출력시키고,
그렇지 않다면 해당 스택의 최상위의 숫자가 송신을 할 수 있으므로 그 숫자를 출력한다.
입력받은 수가 스택의 최상위의 숫자보다 같거나 작다면 인덱스와 해당 숫자를 쌍으로 스택에 넣어준다. 

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N;

	stack<pair<int,int>> stack;

	for (int i = 1;i <= N;i++) {
		cin >> M;
		if (stack.empty()) {
			stack.push({ i, M });
			cout << 0 << ' ';
			continue;
		}
		if (M > stack.top().second) {
			while (!stack.empty() && stack.top().second < M) {
				stack.pop();
			}
			if (stack.empty()) {
				cout << 0 << ' ';
				stack.push({ i, M });
			}
			else {
				cout << stack.top().first << ' ';
				stack.push({ i,M });
			}
		}
		else if (M <= stack.top().second) {
			cout << stack.top().first << ' ';
			stack.push({ i,M });
		}
	}
}
