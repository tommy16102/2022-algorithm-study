#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
vector<string> t1;
vector<string> t2;
map<string, int> m;

int check(string car){
    vector<string> front;
    int idx = m[car];
    for(int i=0;i<idx;i++){
        front.push_back(t1[i]);
    }
    for(int i=0;i<front.size();i++){
        auto it = find(t2.begin(),t2.end(),front[i]);
        if(it == t2.end()) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string car; cin>>car;
        m.insert({car, i});
        t1.push_back(car);
    }
    
    int ret = 0;
    for(int i=0;i<n;i++){
        string car; cin>>car;
        ret += check(car);
        t2.push_back(car);
    }
    cout<<ret;
}
