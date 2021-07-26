#include <iostream>
#include <string>
using namespace std;

/*

☆ 2021.07.26 서혜민

a의 개수 aCount, b의 개수 bCount이라 하며,
나올 수 있는 쌍의 개수는 최대 aCount * bCount개이며,
쌍의 개수 k가 0일 때는, n길이만큼의 B로이뤄진 문자열의 맨 뒤를 A로 바꿔주며
k가 나올 수 있는 최대 쌍의 개수인 a와 b가 각각 문자열 길이의 절반일 때 이므로,
(n/2) * (n/2)보다 크다면 -1을 리턴한다.

aCount를 1부터하여 나올 수 있는 최대 쌍의 개수인 aCount * bCount가 k보다 작다면 건너뛰고,
그렇지 않다면 n-1길이의 B로 이뤄진 문자열을 생성한 뒤 aCount-1개만큼 앞에서부터 A를 채워준다.
이때 생기는 쌍의 개수는 aCount-1 * bCount 이다.
이 수를 k와 비교하여 k와 같다면 더는 쌍이 생길 수 없도록 맨 뒤에 A를 위치시키고
k보다 작다면 쌍의 개수를 늘려줘야 하므로, insert를 통해서 더 많들어야 하는 쌍의 개수만큼 뒤에서부터 앞으로 옮긴 곳에 A를 삽입한다.

*/

int main() {
	//n길이 k쌍
	int n, k;
	cin >> n >> k;
	if (k > (n/(double)2 * n/2)) {
		cout << -1 << endl;
		return 0;
	}
	if (k == 0) {
		string s(n, 'B');
		s[n - 1] = 'A';
		cout << s << endl;
		return 0;
	}

	int aCount, bCount;
	for (aCount = 1;aCount < n;aCount++) {
		bCount = n - aCount;
		if (aCount * bCount < k) continue;
		string s(n-1, 'B');
		for (int i = 0;i < aCount - 1;i++) {
			s[i] = 'A';
		}
		if (k == (aCount * bCount)) {
			s.insert(n-1,"A");
			cout << s << endl;
			return 0;
		}
		else if (k > ((aCount-1) * bCount)) {
			s.insert((n - 1) - (k - (aCount - 1) * bCount), "A");
			cout << s << endl;
			return 0;
		}
	}
}