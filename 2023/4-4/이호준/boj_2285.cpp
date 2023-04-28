/*******************************************************************
Algorithm Study
Baekjoon 2285 우체국
2023/04/28 이호준
# 아이디어
1. 각 사람들까지의 거리라는 정의가 이해가 되지 않았다.
-> 사람 몇명과 가깝냐라는 의미인 것 같다.
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<ll,ll>> inputs(n, {0, 0});

    ll totalPeopleNum = 0;
    for(int i = 0; i < n; i++){
        cin >> inputs[i].first >> inputs[i].second;
        totalPeopleNum += inputs[i].second;
    }

    sort(inputs.begin(), inputs.end());

    ll halfOfPeople = (totalPeopleNum + 1) / 2;
    ll current_people = 0;
    for(auto people : inputs){
        current_people += people.second;
        if(current_people >= halfOfPeople){
            cout << people.first;
            break;
        }
    }

    return 0;
}