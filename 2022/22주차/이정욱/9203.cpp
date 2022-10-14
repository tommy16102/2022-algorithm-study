#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int t,b,c;
vector<pair<string, string>> v;
priority_queue<string, vector<string>, greater<string>> pq;
int _M[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

string toStr(int ii){
    if(ii < 10){
        return "0" + to_string(ii);
    }
    return to_string(ii);
}

string plusClean(string r, string rt, int clean){
    int hh = stoi(rt.substr(0,2));
    int mm = stoi(rt.substr(3,2));
    int ch = clean / 60;
    int cm = clean % 60;
    mm += cm;
    hh += ch;
    
    int YYYY = stoi(r.substr(0,4));
    int MM = stoi(r.substr(5,2));
    int DD = stoi(r.substr(8,2));
    
    if(mm >= 60){
        hh += (mm / 60);
        mm = mm % 60;
    }
    
    if(hh >= 24){
        hh -= 24;
        DD++;
    }
    
    int maxDay = _M[MM];
    if(YYYY == 2016 && MM == 2) maxDay = 29;
    
    if(DD > maxDay){
        DD = 1;
        MM++;
    }
    
    if(MM > 12){
        YYYY++;
        MM = 1;
    }
    
    return toStr(YYYY)+toStr(MM)+toStr(DD)+toStr(hh)+toStr(mm);
}

bool cmp(pair<string, string> a, pair<string, string> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve(){
    cin>>b>>c;
    for(int i=0;i<b;i++){
        string code,r1,r1t,r2,r2t;
        cin>>code>>r1>>r1t>>r2>>r2t;
        string p1 = plusClean(r1,r1t,0);
        string p2 = plusClean(r2,r2t,c);
        v.push_back({p1,p2});
    }
    sort(v.begin(), v.end(), cmp);
    int minRoom = 0;
    for(int i=0;i<v.size();i++){
        while(!pq.empty() && pq.top() <= v[i].first){
            pq.pop();
        }
        pq.push(v[i].second);
        
        minRoom = max(minRoom, int(pq.size()));
    }
    cout<<minRoom<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        v.clear();
        while(pq.size()){
            pq.pop();
        }
        solve();
    }
}
