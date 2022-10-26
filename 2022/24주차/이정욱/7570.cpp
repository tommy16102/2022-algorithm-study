#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,ret,children[1000001],dp[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>children[i];
    }
    
    for(int i=0;i<n;i++){
        dp[children[i]] = dp[children[i]-1]+1;
        ret = max(ret,dp[children[i]]);
    }
    cout<<n-ret;
}
