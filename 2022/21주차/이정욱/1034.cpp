#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,m,k;
map<string,int> row;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(row.find(s) != row.end()){
            row[s]++;
        }else{
            row.insert({s,1});
        }
    }
    cin>>k;
    
//    cout<<"====\n";
    vector<pair<int,int>> res;
    for(auto i=row.begin();i!=row.end();i++){
//        cout<<i->first<<" : "<<i->second<<'\n';
        string s = i->first;
        int on = 0;
        for(int j=0;j<s.size();j++){
            if(s[j] == '1'){
                on++;
            }
        }
        res.push_back({i->second,on});
    }
    
    sort(res.begin(), res.end(),cmp);
    
//    cout<<"=======m이 길이\n";
    for(int i=0;i<res.size();i++){
//        cout<<res[i].first<<" : "<<res[i].second<<" \n";
        int on = res[i].second;
        int cnt = m - on;
        if(cnt<=k && cnt%2 == k%2){
            cout<<res[i].first;
            return 0;
        }
    }
    cout<<"0";
}
