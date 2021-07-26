#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.07.26 서혜민

일단 입력받은 값들을 벡터에 넣어준 뒤, 오름차순으로 정렬 시킨다.
그 뒤, 먼저 0이하인 수들은 앞에서부터 차례대로 두 수씩 끊어서 곱한 값을 벡터에 넣어주고,
0보다 큰 수들은 뒤에서 부터 차례대로 두 수씩 끊어서 곱한 값을 벡터에 넣어주는 데,
이때 음수와는 달리 두 수를 더한 값보다 곱한 값이 더 클 때만 두 수를 묶어서 곱해준다.
또한, 반복문을 진행하면서 이전에 음수를 묶는 과정을 통해 벡터에 음수와 음수의 곱인 양수가 들어가게 되므로
sort를 통해 앞의 수보다 항상 뒤의 수가 같거나 크게 되는 내림차순으로 한번 정렬을 시켰으므로, 이에 맞지 않는 즉,
앞의 수가 뒤의 수보다 큰 수를 만나게 되면 이는 즉 양수에서의 과정은 다 마친 것을 의미하므로 반복문을 빠져나온다.

이후 벡터 내의 수를 모두 더해주면 된다.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v;
	int num;
	while (n--) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	//음수*음수  or 음수*0
	for (int i = 0;i < v.size()-1;i++) {
		if (v[i] > 0) break;
		if (v[i] * v[i + 1] > 0) {
			v[i] = v[i] * v[i + 1];
			v.erase(v.begin()+i+1);
		}

		if (v[i] < 0 && v[i] * v[i + 1] == 0) {
			v[i] = v[i] * v[i + 1];
			v.erase(v.begin() + i + 1);
		}
	}
	
	//양수*양수
	for (int i = v.size() - 1;i > 0;i--) {
		if (v[i - 1] > v[i]) break;
		if (v[i] <= 0) break;
		if (v[i] * v[i - 1] > v[i]+v[i-1]) {
			v[i-1] = v[i] * v[i - 1];
			v.erase(v.begin() + i);
			i--;
		}
	}

	int sum = 0;
	for (auto& i : v) {
		sum += i;
	}
	cout << sum << endl;
}