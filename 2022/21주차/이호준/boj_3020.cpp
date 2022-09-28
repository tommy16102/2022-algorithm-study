/*******************************************************************
Algorithm Study
BAEKJOON 21주차
3020 개똥벌레
2022/09/21 이호준
# 아이디어
1. O(N^2) 불가능
=> 이진탐색 or 누적합

*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, h;
    int answer = INF;
    int count = 0;
    cin >> n >> h;
    
    vector<int> up;
    vector<int> down;
    for(int i = 1; i<= n; i++){
        int height;
        cin >> height;
        if(i % 2){
            up.push_back(height);
        }else{
            down.push_back(height);
        }
    }

   
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    for(int i = 0; i < h; i++){
        int current = up.size() - (lower_bound(up.begin(), up.end(), i + 1) - up.begin());
        //cout << "Test : " << i << "  -> " << current << " " <<answer << " " << count <<"\n";
        current += (down.size() - (lower_bound(down.begin(), down.end(), h - i) - down.begin())); 
        
        //cout << "Test : " << i << "  -> " << current << " " <<answer << " " << count <<"\n";

        if(answer > current){
            answer = current;
            count = 1;
        }else if (answer == current){
            count++;
        }
    }

    cout << answer << ' ' << count << endl;

    return 0;
}