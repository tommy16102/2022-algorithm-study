/*******************************************************************
Algorithm Study
Baekjoon OJ BitMasking
1052 물병
2022/03/26 이호준
# 아이디어
1. bitmasking으로 푸는 방법을 공부해야한다.
*******************************************************************/

#include <cstdio>

int n,k,cnt;

// bit의 값이 1인 개수 찾기
int bit_count(int n)
{
	int ret=0;
	while(n) ret++,n&=n-1;
	return ret;
}

int main()
{
	scanf("%d %d",&n,&k);
	while(bit_count(n)>k)
	{
        // 8 4 2 일때 2를 가져와야 새로운 연산이 가능해지기 때문
        // 가장 오른쪽 1인 값을 한번에 가져온다.
		cnt+=n&-n; // bit가 1인 것 중에서 가장 오른쪽 bit를 가져오는 연산
		n+=n&-n;
	}
	printf("%d\n",cnt);
	return 0;
}

// #include <iostream>

// using namespace std;

// int main(void) {

// 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// 	int n, k;

// 	cin >> n >> k; 
// 	if (n <= k) {
// 		cout << 0 << "\n";
// 		return 0; 
// 	} 
// 	int result; 
// 	for (result = 0; ; result++) {
// 		int cnt = 0; 
// 		int tempN = n; 
// 		while (tempN) {
// 			if (tempN % 2) {
// 				cnt++; 
// 			} 
// 			tempN /= 2; 
// 		} if (cnt <= k) {
// 			break; 
// 		}
// 		n++; 
// 	} 
// 	cout << result << "\n";

// 	return 0;
// }