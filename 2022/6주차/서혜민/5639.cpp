#include <iostream>
#include <vector>
using namespace std;

/*
50	30	24	5	28	45	98	52	60
r   lr                  rr
    r   lr          rr  r   lr
	    r  lr   rr          r   rr

start를 처음 입력받는 50, end를 마지막에 입력받는 60으로 설정하여 트리 내 전체 요소를 시작으로
이후부터 왼쪽 서브트리와 오른쪽 서브트리로 분리하여 피라미터를 서브트리의 각각의 root와 마지막 요소로
설정하여 print함수를 실행하면서 후위 순회로 출력.

*/

vector<int> v;

void print(int start, int end) {
	int index = end + 1;

	if (start > end) return;

	for (int i = start + 1;i <= end;i++) {
		if (v[i] > v[start]) {
			index = i;
			break;
		}
	}

	print(start + 1, index - 1);
	if(index < end + 1) print(index, end);
	cout << v[start] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n) {
		v.push_back(n);
	}

	print(0, v.size()-1);
}
