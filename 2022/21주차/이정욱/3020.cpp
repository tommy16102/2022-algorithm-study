#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,h;
int res[500001];
vector<int> suck; //석순
vector<int> jong; //종유석

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>h;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(i%2 == 0){
            suck.push_back(a);
        }else{
            jong.push_back(a);
        }
    }
    
    sort(suck.begin(),suck.end());
    sort(jong.begin(),jong.end());
    
    int idx = 0;
    int here = 1;
    
    while(here <= h && idx < n/2){
        if(here <= suck[idx]){
            res[here] = (n/2-idx);
            here++;
        }else{
            idx++;
        }
    }
    
    idx = 0;
    here = 1;
    int to = h;
    
    while(here <= h && idx < n/2){
        if(here <= jong[idx]){
            res[to] += (n/2-idx);
            here++;
            to--;
        }else{
            idx++;
        }
    }
    sort(res + 1, res + h+1);
    int min = res[1];
    here = 2;
    while(min == res[here]){
        here++;
    }
    cout<<min<<" "<<here-1;
}
