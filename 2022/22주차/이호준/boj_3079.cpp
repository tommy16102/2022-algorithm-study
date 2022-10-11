/*******************************************************************
3079 입국심사
2022/10/11 이호준
# 아이디어
1. Parametric Search
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> times(n, 0);
    for(int i = 0; i < n; i++){
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    long long left = 1;
    long long right = times[times.size()-1] * m;
    long long answer = right;

    while(left <= right){
        long long mid = (left + right) / 2;
        
        long long sum = 0;
        for(int i = 0; i< times.size(); i++){
            sum += mid / times[i];
        }
        if(sum >= m){
            answer = min(answer, mid);
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}