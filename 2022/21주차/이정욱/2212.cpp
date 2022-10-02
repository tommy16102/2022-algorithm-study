#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,s[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    
    
    sort(s,s+n);
    vector<int> v;
    for(int i=0;i<n-1;i++){
        v.push_back(s[i+1] - s[i]);
    }
    
    sort(v.begin(), v.end());
    int res = 0;
    
    for(int i=0;i<n-k;i++){
        res += v[i];
    }
    cout<<res;
}
