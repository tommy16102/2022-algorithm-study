/*******************************************************************
Algorithm Study
Baekjoon 14476 최대공약수 하나 빼기
2023/05/19 이호준
# 아이디어
1. 유클리드 호제법과 누적합의 조합
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> inputs(n, 0);

    for(int i = 0; i < n; ++i){
        cin >> inputs[i];
    }

    vector<int> leftToRight(n, 0);
    vector<int> rightToLeft(n, 0);
    leftToRight[0] = inputs[0];
    rightToLeft[n - 1] = inputs.back();
    for(int i = 1; i < n; ++i){
        leftToRight[i] = gcd(max(inputs[i], leftToRight[i-1]), min(inputs[i], leftToRight[i-1]));
    }

    for(int i = n - 2; i >= 0; --i){
        rightToLeft[i] = gcd(max(inputs[i], rightToLeft[i + 1]), min(inputs[i], rightToLeft[i+1]));
    }

    int result = -1;
	int except = -1;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			result = max(result, rightToLeft[1]);
			except = inputs[i];
		}else if (i == n - 1) {
			if (result < leftToRight[n-2]) {
				result = leftToRight[n-2];
				except = inputs[i];
			}
		}else{
			if(result < gcd(max(leftToRight[i - 1], rightToLeft[i + 1]), min(leftToRight[i - 1], rightToLeft[i + 1]))){
				result = gcd(max(leftToRight[i - 1], rightToLeft[i + 1]), min(leftToRight[i - 1], rightToLeft[i + 1]));
				except = inputs[i];
			}
		}
	}

	if (except % result == 0) {
		cout << -1;
	}else {
		cout << result << " " << except;
	}

    return 0;
}