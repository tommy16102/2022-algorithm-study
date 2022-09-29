#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,l;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>l;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    v.push_back(0);
    v.push_back(l);
    sort(v.begin(), v.end());
    
    int left = 1, right = (l+1)/2, res = 0;
    while(left <= right){
        int mid = (left + right)/2;
        if(mid == 0){
            cout<<1;
            return 0;
        }
        int cnt = 0;
        for(int i=0;i<v.size()-1;i++){
            int len = v[i+1] - v[i];
            cnt += len / mid;
            if(len % mid == 0) cnt--;
        }
        if(cnt > m){
            left = mid+1;
        }else{
            res = mid;
            right = mid-1;
        }
    }
    cout<<res;
}
