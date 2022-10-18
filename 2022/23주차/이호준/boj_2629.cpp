/*******************************************************************
2629 양팔저울
2022/10/18 이호준
# 아이디어
1. DP

본래 1차원 DP 인줄알았으나 그것으로 해결할 수 없었따. 2차원 배열로 구현했어야헀다.
최대 30개 500g의 추는 최대 15000이고 내가 놓을 추는 500g이 될 수 있으므로 인덱스가 음수가 되지 않도록
15501을 기본으로 두고 연산했어야했다.
*******************************************************************/
#include <iostream>

using namespace std;

int weights[31];

int n, w, answers;

bool DP[31][40001];

void dp(){
	DP[0][15501] = true;
	DP[0][15501 - weights[0]] = true;
	DP[0][15501 + weights[0]] = true;

	for (int i = 1; i < n; i++) {

		int checkWeight = weights[i];
		
		for (int j = 500; j < 40001; j++) {

			DP[i][j] = DP[i - 1][j - checkWeight] || DP[i - 1][j] || DP[i - 1][j + checkWeight];

		}

	}

}

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> w;
		weights[i] = w;
	}
	
    dp();

	cin >> answers;
	for (int i = 0; i < answers; i++) {
		cin >> w;

		if (DP[n-1][15501 + w]) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}

	}

	return 0;
}