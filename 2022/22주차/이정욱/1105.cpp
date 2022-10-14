#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string l,r;
int ret;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>l>>r;
    
    if(l.size() != r.size()){
        cout<<0<<"\n";
        return 0;
    }
    
    for(int i=0;i<l.size();i++){
        if(l[i] == r[i]){
            if(l[i] == '8') ret++;
            continue;
        }
        break;
    }
    cout<<ret<<"\n";
}
