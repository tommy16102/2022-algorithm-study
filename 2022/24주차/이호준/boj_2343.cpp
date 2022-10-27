/*******************************************************************
2343 기타레슨
2022/10/23 이호준
# 아이디어
1. Parametric Search
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll sum[100001];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<long long> classes(n, 0);

    ll left = 0;
    ll answer = 0;
    ll sum = 0;

    for(int i = 0; i < n; i++){
        cin >> classes[i];
        left = max(left, classes[i]);
        sum += classes[i];
    }

    ll right = sum;


    while(left <= right){
        ll mid = (left + right) / 2;

        ll bluray = 0;
        ll temp_sum = 0;
        for(int i = 0; i < n; i++){
            if(temp_sum + classes[i] > mid){
                temp_sum = 0;
                bluray++;
            }
            temp_sum += classes[i];
        }
        
        if(temp_sum != 0)
            bluray++;

        if(bluray <= m){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}