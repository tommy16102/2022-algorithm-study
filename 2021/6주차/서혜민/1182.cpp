#include <iostream>
#include <vector>
using namespace std;

/*

2021.08.11 서혜민

앞에서부터 차례대로 값을 더해가면서 입력한 S와 같아질 때마다 count증가

*/


int N, S;
vector<int> v;
int count = 0;

void find(int index, int sum) {
	if (sum == S) {
		::count++;
	}
	for (int i = index + 1;i < N;i++) {
		find(i, sum + v[i]);
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0;i < N;i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	for (int i = 0;i < N;i++) {
		find(i, v[i]);
	}
	
	cout << ::count << endl;
}
