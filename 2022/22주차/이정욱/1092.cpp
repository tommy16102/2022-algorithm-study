#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> crain, box;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int c; cin>>c;
        crain.push_back(c);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int b; cin>>b;
        box.push_back(b);
    }
    sort(crain.begin(), crain.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    
    if(crain[0] < box[0]){
        cout<<"-1\n";
        exit(0);
    }
    
    int ret = 0;
    
    while(1){
        for(int i=0;i<n;i++){
            for(int j=0;j<box.size();j++){
                if(box[j] <= crain[i]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
        
        ret++;
        if(box.empty()) break;
    }
    cout<<ret;
}
