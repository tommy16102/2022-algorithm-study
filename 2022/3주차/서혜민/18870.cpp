#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.1.23

입력받은 수 벡터에 저장한 뒤, 정렬 후 중복 제거.
이후 lower_bound를 통해 같거나 큰 숫자가 몇 번째에 등장하는 지 확인.

*/

int main() {
	int N;
	cin >> N;

	vector<int> v(N), org(N);
	for (int i = 0;i < N;i++) {
		cin >> org[i];
		v[i] = org[i];
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (int i = 0;i < N;i++) {
		cout << lower_bound(v.begin(), v.end(), org[i]) - v.begin() << ' ';
	}
}
