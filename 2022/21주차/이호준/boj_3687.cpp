/*******************************************************************
Algorithm Study
BAEKJOON 21주차
3687 성냥개비
2022/10/05 이호준
# 아이디어
1. DP
*******************************************************************/
#include <iostream>
#include <climits>
 
#define INF 2100000000

using namespace std;
 
int n, testcase;
int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
long long minDP[101] = {0, };
 
void minCal(){
    for(int i=1; i<=9; i++){
        minDP[i] = num[i];
    }
    minDP[6] = 6; // 처음 시작은 0으로 할 수 없으니, 6으로 시작
    // 또한, 9부터 시작하는 이유는, 8부터 하면 10이 아닌, 08(j=7일 경우) 값을 최소로 인식한다.
    for(int i=9; i<=100; i++){
        minDP[i] = INF;
        for(int j=2; j<8; j++){
            minDP[i] = min(minDP[i], minDP[i-j]*10+num[j]);
        }
    }
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>testcase;
    minCal(); 
    while(testcase--){
        cin>>n;

        cout<<minDP[n]<<" ";
 
        while(n){
            if(n % 2 != 0){
                cout << 7;
                n -= 3;
            }
            else{
                cout << 1;
                n -= 2;
            }
        }
        cout << "\n";
    }
 
    return 0;
