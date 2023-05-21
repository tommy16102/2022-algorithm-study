/*******************************************************************
Algorithm Study
Baekjoon 10986 나머지 합
2023/05/18 이호준
# 아이디어
1. 누적합
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll counts[1001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, x;
    cin >> n >> m;

    ll sum = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		sum += x;
		counts[sum % m]++;
	}
    
    ll answer = counts[0];
	for (int i = 0; i < 1000; i++){
		answer += counts[i] * (counts[i] - 1) / 2; // combination
	}
	
	cout << answer;
    return 0;
}