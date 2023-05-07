#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, -1, 1, 0};
char dc[4] = {'d', 'l', 'r', 'u'};
map<string, bool> v;
typedef struct info{
    int y;
    int x;
    string r;
    info(int Y, int X, string R) : y(Y), x(X), r(R) {}
}info;

struct cmp{
    bool operator()(const info a, const info b){
        return a.r > b.r;
    }
};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    if(abs(r-x) + abs(c-y) > k) return "impossible";
    pair<int,int> start = {x-1, y-1};
    pair<int,int> goal = {r-1, c-1};
    
    priority_queue<info, vector<info>, cmp> pq;    
    pq.push(info(x-1, y-1, ""));
    while(!pq.empty()){
        info cur = pq.top();
        int y = cur.y;
        int x = cur.x;
        string r = cur.r;
        if(r.size() == k && make_pair(y,x) == goal) {return r;}
        if(r.size() > k) break;
        pq.pop();
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && 
               abs(ny-goal.first) + abs(nx-goal.second) <= k - (r.size()+1) && !v[r]){
                v[r] = true;
                pq.push(info(ny, nx, r+dc[i]));                
            }
        }
    }
    return "impossible";
}
