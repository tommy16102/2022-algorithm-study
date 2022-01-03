#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

2021.09.08 
AB/CD로 나누어 벡터 2개에 저장.
이 벡터 2개 중 하나는 맨 앞을 가리키는 front, 하나는 맨 뒤를 가리키는 back을 줘서
가리키는 수의 합이 0일 때 count를 하나씩 늘려준다.
합이 0보다 크다면 숫자가 감소해야하므로 back은 한칸 앞으로
0보다 작다면 숫자를 키워야하므로 front를 뒤로,
이때 숫자가 중복이 가능하므로 xcount와 ycount라는 변수를 둬서 while문을 통해 같은 수가 나오면 이를 늘려준다.
이후 이 두 변수의 값을 곱하면 모든 개수가 된다.

*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long int> v1(n*n), v2(n*n);
	vector<long long int> A(n), B(n), C(n), D(n);

	for (int i = 0;i < n;i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	int index = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			v1[index]=A[i] + B[j];
			v2[index]=C[i] + D[j];
			index++;
		}
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int front = 0, back = n * n - 1;
	long long int count = 0;
	while (front < v1.size() && back >= 0) {
		long long int sum = v1[front] + v2[back];
		if (sum == 0) {
			long long int xcount = 0, ycount = 0;
			int x = v1[front]; int y = v2[back];
			while (v2[back] == y) {
				ycount++;
				back--;
				if (back ==-1) break;
			}
			while (v1[front] == x) {
				xcount++;
				front++;
				if (front == v1.size()) break;
			}
			count += (ycount*xcount);
			continue;
		}
		if (sum > 0) back--;
		else front++;
	}
	cout << count << '\n';
}
