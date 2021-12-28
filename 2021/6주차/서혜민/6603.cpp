#include <iostream>
#include <vector>
using namespace std;

/*

2021.08.16 서혜민

사전순으로 출력이 되므로, 해당 인덱스부터 현재 벡터의 길이에서 얼만큼의 숫자가 들어가야 길이가 6이 되는지를 고려해서
앞에서부터 그만큼 for문을 통해서 각각의 숫자를 넣어주는 과정을 재귀적으로 반복한다.

*/

void getLotto(vector<int>& v, int index, vector<int> &org) {
	if (v.size() == 6) {
		for (int i = 0;i < v.size();i++) cout << v[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = index+1;i <= org.size() - (6 - v.size());i++) {
		vector<int> vv=v;
		vv.push_back(org[i]);
		getLotto(vv, i, org);
	}
}

int main() {
	while (1) {
		int K;
		cin >> K;
		int cnt = K;
		if (K == 0) break;
		vector<int> v(K);
		for (int i = 0;i < K;i++) cin >> v[i];

		for (int i = 0;i <= cnt - 6;i++) {
			vector<int> vv;
			vv.push_back(v[i]);
			getLotto(vv, i, v);
		}
		cout << endl;
	}
}
