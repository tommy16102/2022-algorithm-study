/*******************************************************************
1561 놀이 공원
2022/10/14 이호준
# 아이디어
1. Parametric Search
*******************************************************************/

#include <iostream>
#include <vector>
#define MAXTIME 60000000000

typedef long long ll;


using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<ll> attraction(m, 0);

    for(int i = 0; i < m; i++){
        cin >> attraction[i];
    }

    if(n <= m){
        cout << n;
        return 0;
    }


    ll left = 0;
    ll right = MAXTIME;
    ll answer = 0;

    while(left <= right){
        ll mid = (left + right) / 2;

        ll current_member = m;
        for(int i = 0; i < m ; i++){
            current_member += mid / attraction[i];
        }

        if(current_member >= n){
            right = mid - 1;
            answer = mid;
        }else{
            left = mid + 1;
        }
    }

    ll cnt = m;
    for(int i = 0; i < m; i++) 
        cnt += (answer - 1) / attraction[i];
    for(int i = 0; i < m; i++) {
        if(answer % attraction[i] == 0) 
            cnt++;
        if(cnt == n) {
            cout << i + 1 ;
            break;
        }
    }

    return 0;
}