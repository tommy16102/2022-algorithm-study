#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 정환훈
    푼 날짜 : 2021/07/21

    기본 아이디어 : 0 있는지 체크? 3으로 나눠지는지 체크? 그럼 이제 큰 수대로 정렬!

*/

int main() {

	string N;

	cin >> N;

	vector<int> n;

	for (int i = 0; i < N.size(); i++) {
		n.push_back(N[i] - '0');
	}


	int flag = 0;
	int sum = 0;

	for (int i = 0; i < n.size(); i++) {
		if (n[i] == 0)
			flag = 1;
		sum += n[i];
	}

	if (flag == 0) {
		cout << -1;
		return 0;
	}
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}

	sort(n.begin(), n.end(), greater<int>());

	string answer = "";
	for (int i = 0; i < n.size(); i++) {
		answer += to_string(n[i]);
	}
	
	cout << answer;

	return 0;
}