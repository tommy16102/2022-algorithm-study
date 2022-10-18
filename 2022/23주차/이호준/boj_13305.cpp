/*******************************************************************
13305 주유소
2022/10/8 이호준
# 아이디어
1. Greedy
*******************************************************************/
#include <iostream>

using namespace std;

typedef long long ll;
ll oil_price[100000];
ll road[100000];

int main() {
	ll city;
	ll min;
	ll total;

	cin >> city;	

	for (int i = 0; i < city - 1; i++) {
		cin >> road[i];	
	}

	for (int i = 0; i < city; i++) {
		cin >> oil_price[i];	
	}

	min = oil_price[0];
	total = min * road[0];

	for (int i = 0; i < city; i++) {
		if (min >= oil_price[i + 1]) {	
			min = oil_price[i + 1];	
		}
		total += min * road[i + 1];
	}
	

	cout << total;

	return 0;
}