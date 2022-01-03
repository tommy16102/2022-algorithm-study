#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

    푼 날짜 : 2021/07/30
    기본 아이디어 : DP 
    
    
	//이친수는 0으로 시작하지 않는다.
	//이친수에서는 1이 두 번 연속으로 나타나지 않는다.즉, 11을 부분 문자열로 갖지 않는다.
    // d[2][1] = 2자리수인데 1로 끝남
    // d[i][1] = d[i-1][0]
	// d[i][0] = d[i-1][0] + d[i-1][1]
*/

int main() {


	int n;
	cin >> n;

	long long** d = new long long*[100];

	for (int i = 0; i < 100; i++) {
		d[i] = new long long[2];
		for (int j = 0; j < 2; j++) {
			d[i][j] = 0;
		}
	}
	


	
	d[1][1] = 1;
	d[2][0] = 1;



	for (int i = 2; i < 100; i++) {
		
		d[i][1] = d[i - 1][0];
		d[i][0] = d[i - 1][0] + d[i - 1][1];
	}

	cout << d[n][0] + d[n][1];


	return 0;
}
