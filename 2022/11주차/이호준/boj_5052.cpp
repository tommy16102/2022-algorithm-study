/*******************************************************************
Algorithm Study
Baekjoon OJ 
5052 접두어
2022/04/12 이호준
# 아이디어
1. string 정렬을 통해서 접두어를 파악한다.
string을 사전식 정렬하고 뒤에 문자열에 대해서 앞에 문자가 포함되어 있는지 그 위치가 접두어인지 확인하면 된다.
string을 사전식 정렬하면
*******************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        vector<string> inputs(n, "");

        for(int i =0 ;i<n; i++){
            cin >> inputs[i];
        }

        sort(inputs.begin(), inputs.end());
        // for(auto a : inputs){
        //     cout << a << " \n";
        // }

        bool isThere = false;
        
        for(int i = 0; i< n-1; i++){
            int index = inputs[i+1].find(inputs[i]);
            if( index != string::npos && index == 0){
                isThere = true;
                break;
            }
        }
        cout << ((isThere ? "NO" : "YES")) << "\n";
    }


    return 0;
}