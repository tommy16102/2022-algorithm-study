#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int ma; int mc; int mt = 987654321;
map<pair<int,pair<int,int>>, int> cache;
vector<vector<int>> p;
int go(int a, int c, int t){
    if(a >= ma && c >= mc){
        return t;
    }
    if(cache.find({a, {c, t}}) != cache.end()) return cache[{a, {c, t}}];
    int ret = 987654321;
    for(int i=0;i<p.size();i++){
        vector<int> cp = p[i];
        if(a < cp[0]){
            ret = min(ret, go(cp[0], c, t+(cp[0]-a)));
        }
        if(c < cp[1]){
            ret = min(ret, go(a, cp[1], t+(cp[1]-c)));
        }
        if((a >= cp[0] && c >= cp[1]) && ((cp[3] > 0 && c < mc) || (cp[2] > 0 && a < ma))){
            ret = min(ret, go(a+cp[2], c+cp[3], t+cp[4]));
        }
    }
    return cache[{a, {c, t}}] = ret;
}
int dp[515][515];
// [alp_req, cop_req, alp_rwd, cop_rwd, cost]
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for(int i=0;i<515;i++){
        for(int j=0;j<515;j++){
            dp[i][j] = 987654321;
        }
    }
    p = problems;    
    for(auto p : problems){
        ma = max(ma, p[0]);
        mc = max(mc, p[1]);
    }
    //return go(alp, cop, 0);
    alp = min(alp, ma); cop = min(cop, mc);
    dp[alp][cop] = 0;
    int x, y;
    for(int i=alp;i<=ma;i++){
        for(int j=cop;j<=mc;j++){
            x = min(i+1, ma);
            y = min(j+1, mc);
            dp[x][j]=min(dp[x][j], dp[i][j]+1);
            dp[i][y]=min(dp[i][y], dp[i][j]+1);
            for(int k=0; k<problems.size(); k++){
                int alp_req=problems[k][0];
                int cop_req=problems[k][1];
                int alp_rwd=problems[k][2];
                int cop_rwd=problems[k][3];
                int cost=problems[k][4];
                if(i < alp_req || j < cop_req) continue;                
                x = min(i+alp_rwd, ma);
                y = min(j+cop_rwd, mc);
                dp[x][y]=min(dp[x][y], dp[i][j]+cost);
            }
        }
    }
    return answer=dp[ma][mc];
}
