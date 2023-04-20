/*******************************************************************
Algorithm Study
Baekjoon 1976 여행가자
2023/04/19 이호준
# 아이디어
1. Union-Find
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int route[201];

int find(int x){
    if(route[x] == x)
        return x;
    return route[x] = find(route[x]);
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        route[i] = i;

    int temp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> temp;
            if(temp){
                int a = find(i);
                int b = find(j);
                if(a != b){
                    if(a > b){
                        route[a] = b;
                    }else{
                        route[b] = a;
                    }
                }
            }
        }
    }
    vector<int> routes(m, 0);
    for(int i = 0; i < m; i++){
        cin >> routes[i];
    }
    for(int i = 0; i < m - 1; i++){
        int start = find(routes[i]);
        int end = find(routes[i + 1]);
        if(start != end){
            cout << "NO";
            return 0;
        }
    }
    cout <<"YES";
    return 0;
}