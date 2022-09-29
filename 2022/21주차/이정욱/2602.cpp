#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string a,b[2];
int dp[2][101][21];

int go(int bridge, int here, int idx){
    if(idx == a.size()) return 1;
    int &ret = dp[bridge][here][idx];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=here;i<b[0].size();i++){
        if(b[bridge][i] == a[idx]){
            ret += go(!bridge, i+1, idx+1);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>a>>b[0]>>b[1];
    
    memset(dp, -1, sizeof(dp));
    int res = 0;
    res += go(0,0,0);
    res += go(1,0,0);
    cout<<res;
}
