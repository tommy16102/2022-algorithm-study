#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

/*
2021.12.29 서혜민

벡터에 수를 계속 넣어주면서, 이미 벡터에 존재하는 수가 들어간다면
그 때부터는 반복수열이 되므로, 해당 수의 벡터 내 인덱스를 알아낸다.

find(v.begin(), v.end(), A) - v.begin()을 통해 A의 v내 인덱스를 알 수 있다.

*/

int makeNum(int num, int powNum) {
	int res = 0;
	string sNum = to_string(num);
	for (int i = 0;i < sNum.length();i++) {
		res += pow(sNum[i]-'0', powNum);
	}
	return res;
}

int main() {
	int A, P;
	cin >> A >> P;

	vector<int> v;
	while (find(v.begin(), v.end(), A) == v.end()) {
		v.push_back(A);
		A = makeNum(A, P);
	}
	
	cout << find(v.begin(), v.end(), A) - v.begin() << '\n';
}
