#include <iostream>
#include <vector>
using namespace std;


/*

2021.08.16 서혜민

num이라는 배열의 인덱스는 만들어진 수열 내 수의 합을 의미하며, 입력받은 수는 1개의 수를 가지는 수열이므로 이들을 먼저 1로 한 뒤,
재귀를 통해 수열을 만들면서 그 수열 내 수들의 합인 인덱스를 1로 설정한다.

앞에서부터 num배열 내 원소 값이 1이 아닌 인덱스가 답이된다.

*/


bool num[100000*20+1];
vector<int> v;
int N;

void makeNum(int index, int sum) {
	num[sum] = 1;
	for (int i = index + 1;i < N;i++) {
		makeNum(i, sum + v[i]);
	}
}

int main() {
	cin >> N;
	int count = N;
	while (count--) {
		int n;
		cin >> n;
		num[n] = 1;
		v.push_back(n);
	}

	for (int i = 0;i < v.size();i++) {
		makeNum(i, v[i]);
	}

	int index = 1;
	while (1) {
		if (!num[index]) {
			cout << index << endl;
			return 0;
		}
		index++;
	}
}
