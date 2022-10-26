#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int t,result;
string s;

void check(int start, int end, int cnt){
    if(start >= end){
        result = cnt;
        return;
    }
    if(s[start] == s[end]){
        check(start+1,end-1,cnt);
    }else{
        if(cnt == 0){
            check(start+1, end, cnt+1);
            if(result == 2){
                check(start,end-1,cnt+1);
            }
        }else{
            check(1,0,cnt+1);
        }
    }
}

void go(){
    cin>>s;
    check(0,int(s.size())-1,0);
    cout<<result<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        go();
    }
}
