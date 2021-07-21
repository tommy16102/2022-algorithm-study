#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*

2021.07.26 서혜민

30의 배수란, 10의 배수이면서 모든 자리의 합이 3의 배수인 수이다.
sort를 통해서 가장 큰 수가 앞에 오는 식으로 정렬한 뒤,
각 자리수의 합을 더하고, 0의 개수를 세서,
0이 없거나, 각 자리의 합이 3의 배수가 아니면 -1을 리턴
그렇지 않으면 정렬된 수를 리턴.

*/

int main() {
	string n;
	cin >> n;
	sort(n.begin(), n.end(), greater<>());
	
	int count = 0;
	int sum = 0;
	for (int i = 0;i < n.size();i++) {
		if (n[i] == '0') count++;
		sum += n[i] - '0';
	}

	if (count && !(sum % 3)) cout << n << endl;
	else cout << -1 << endl;
}