#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*

2021.08.23 서혜민

각 집합 별 부모가 존재하는 분리 집합을 이용한 문제.
arr배열은 각 숫자를 인덱스로서 해당 숫자가 속한 집합의 부모를 값으로서 가지는 배열.

op가 0일 때는 a와 b의 집합을 합쳐야하므로, 이 둘의 최상 부모를 찾아내어, 뒤에 오는 b의 최상부모를 a의 최상부모로 설정을 하면
이 집합은 동일한 최상 부모를 가진 하나의 집합이 된다.
op가 1일 때는 입력 받은 a, b의 최상 부모를 알아내어 이 둘이 같으면 같은 집합에 포함된 것을 의미한다.

*/

int arr[1000001];

int getParent(int index) {
	if (arr[index] == -1) return index;
	return arr[index]=getParent(arr[index]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	memset(arr, -1, sizeof(arr));

	int op, a, b;
	while (m--) {
		cin >> op >> a >> b;
		if (!op) {
			int parentA = getParent(a);
			int parentB = getParent(b);
			if (parentA == parentB) continue;
			else arr[parentB] = parentA;
		}
		else {
			if (getParent(a) == getParent(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}
