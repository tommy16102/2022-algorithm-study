/*******************************************************************
Algorithm Study
BAEKJOON 21주차
2212 센서
2022/09/29 이호준
# 아이디어
1. 정렬 및 그리디
k개로 나누는데 결국 차의 합이 최소가 되어야하는 것이 문제
문제 이해가 어려웠고
풀이도 바로 생각해내지 못했다.
문제를 이해하고 차이를 통해 결국 차가 큰것들을 제외해야한다는 것을 봤어야한다.
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000


using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    int answer = 0;

    cin >> n >> k;

    vector<int> sensors(n, 0);

    for(int i = 0; i< n; i++){
        cin >> sensors[i];
    }

    sort(sensors.begin(), sensors.end());

    vector<int> diff(n-1, 0);

    for(int i = 0; i < n - 1; i++){
        diff[i] = sensors[i+1] - sensors[i];
    }

    sort(diff.begin(), diff.end());
    
    for(int i = 0; i < n - k; i++){
        answer += diff[i];
    }

    cout << answer;

    return 0;
}