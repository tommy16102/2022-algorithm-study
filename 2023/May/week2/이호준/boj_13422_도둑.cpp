/*******************************************************************
Algorithm Study
Baekjoon 13422 도둑
2023/05/14 이호준
# 아이디어
1. 슬라이딩 윈도우
*******************************************************************/

#include <iostream>

using namespace std;

int a[100000];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        int ans=0,sum=0;
        for(int i = 0; i < m; i++)
            sum+=a[i];
        if(sum < k) 
            ans++;
        if(n != m){
            for(int i = 1; i < n; i++){
                sum -= a[i-1];
                sum += a[(i + m - 1) % n];
                if(sum<k) {
                    ans++;
                }
            }
        }
        cout << ans <<"\n";
    }
}