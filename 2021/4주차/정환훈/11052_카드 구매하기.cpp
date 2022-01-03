#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*

    푼 날짜 : 2021/07/28
    기본 아이디어 : 현재값 + 1이랑 약수 * 배수 한거랑 i-랑 i랑 다 더해서...
    삽질 개많이함
	
*/


int main() {

	int n;

	cin >> n;

	int* price = new int[n + 1]; // 1~n
	int* memo = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		price[i] = temp;;
	}

	// 1 5 2 4 3 3
	memo[0] = 0; price[0] = 0;
	memo[1] = price[1];
	for (int i = 2; i <= n; i++) { // 
		int big = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				int temp = price[j] * (i / j);
				if (big < temp)
					big = temp;
			}
		}
		memo[i] = max(memo[i - 1] + price[1], big);

		for (int j = 0; j <= i; j++) {
			if (memo[j] + memo[i - j] > memo[i]) { // i=7에서 1원+memo(6)보다 memo(3)+memo(4)가 최대가 되는 경우
				memo[i] = memo[j] + memo[i - j];
			}
		}
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << i << "   " << memo[i] << endl;
	//}


	cout << memo[n];
	return 0;
}