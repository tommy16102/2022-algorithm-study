/*******************************************************************
11399 ATM
2022/10/10 이호준
# 아이디어
1. 그리디
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> times(n, 0);

    for(int i = 0; i<n; i++){
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (n-i) * times[i];
    }
    cout <<sum;
    return 0;
}