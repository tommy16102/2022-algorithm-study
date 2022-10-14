#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n,m,maxN,arr[100001];

bool check(ll mid){
    ll c = 0;
    for(int i=0;i<n;i++){
        ll can = mid / arr[i];
        c += can;
    }
    if(c >= m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxN = max(maxN,arr[i]);
    }
    ll l=1,r=m*maxN;
    ll ret = r;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            ret = min(ret,mid);
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout<<ret;
}
