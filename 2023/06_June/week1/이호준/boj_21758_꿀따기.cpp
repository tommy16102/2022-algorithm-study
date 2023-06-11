/*******************************************************************
Algorithm Study
Baekjoon 21758 꿀따기
2023/06/11 이호준
# 아이디어
1. 누적합
*******************************************************************/
#include <iostream>

#define MAX 100001

using namespace std;

int arr[MAX], sum[MAX];

int getPrefixSum(int a, int b) {
    return sum[b] - sum[a - 1]; 
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	int res = 0;
	for (int i = 2; i < n; i++)
		res = max(res, getPrefixSum(2, n) + getPrefixSum(i + 1, n) - arr[i]);

	for (int i = n - 1; i > 1; i--)
		res = max(res, getPrefixSum(1, n - 1) + getPrefixSum(1, i - 1) - arr[i]);

	for(int i = 2; i <= n - 1; i++)
		res = max(res, getPrefixSum(2, n - 1) + arr[i]);

	cout << res;
	return 0;
}