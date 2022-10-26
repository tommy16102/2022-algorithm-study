#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,visited[10001];
vector<int> relation[10001];

int go(int x){
    visited[x] = 1;
    int cnt = 0;
    if(relation[x].empty()) return 0;
    for(int i=0;i<relation[x].size();i++){
        int nx = relation[x][i];
        if(visited[nx]) continue;
        cnt += go(nx) + 1;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        relation[b].push_back(a);
    }
    
    int result[n];
    int maxC = 0;
    
    for(int i=1;i<=n;i++){
        memset(visited, 0, sizeof(visited));
        result[i] = go(i);
        maxC = max(maxC, result[i]);
    }
    
    for(int i=1;i<=n;i++){
        if(result[i] == maxC){
            cout<<i<<" ";
        }
    }
}
