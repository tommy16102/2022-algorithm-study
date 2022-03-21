/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
20055 컨베이어 벨트 위의 로봇
2022/03/18 이호준
# 아이디어
1. 맨앞과 뒤에서 데이터의 변동이 필요하다 => deque 덱의 자료구조가 필요하다.
그 이후 원하는 데로 구현을 한다.
먼저 push_back으로 넣어서 1의 위치를 front()로 하고 항상 back()에서 떨어지도록 한다.
=> 자료구조에 넣고 빼는 구조를 결정
*******************************************************************/
#include <iostream>
#include <deque>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	deque<pair<int, bool>> up;
	deque<int> down;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		up.push_back({ temp, false });
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		down.push_back(temp);
	}

	int zero = 0;
	int step = 1;
	while (1) {
		int temp1, temp2;
		temp1 = down.back();
		temp2 = up.back().first;
		up.pop_back();
		down.pop_back();
		up.push_front({temp1,false});
		down.push_front(temp2);

		for (auto iter = up.rbegin(); iter != up.rend(); ++iter) {
			if ((*iter).second) {
				if (iter == up.rbegin()) {
					(*iter).second = false;
				}
				else if(!(*(iter-1)).second && (*(iter-1)).first >=1) {
					auto temp = iter - 1;
					(*temp).second = true;
					(*iter).second = false;
					(*temp).first--;
					if (temp == up.rbegin()) {
						(*temp).second = false;
					}
					if ((*temp).first == 0) {
						zero++;
					}
				}
			}
		}

		if (up.front().first > 0) {
			up.front().second = true;
			up.front().first--;
			if (up.front().first == 0) {
				zero++;
			}
		}
		if (zero >= k) {
			break;
		}
		step++;
	}

	cout << step;

	return 0;
}