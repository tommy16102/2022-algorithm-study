#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,result,arr[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
    }
    
    for(int i=0;i<n;i++){
        result += arr[i];
    }
    cout<<result;
}
