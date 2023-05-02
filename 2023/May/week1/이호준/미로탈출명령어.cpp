/*******************************************************************
Algorithm Study
2023 KAKAO BLIND RECRUITMENT 미로 탈출 명령어
2023/05/02 이호준
# 아이디어
1. DFS
*******************************************************************/
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Point{
  int x, y;  
};

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string moveDir = "dlru";
int n, m;

string temp = "";
string answer;

bool inRange(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= m;
}

int calDistance(Point cur, Point target){
    return abs(cur.x - target.x) + abs(cur. y - target.y);
}

void dfs(int step, int k, Point cur, Point target, bool& flag){
    if(flag) return;
    
    if(step == k){
        if(cur.x == target.x && cur.y == target.y){
            flag = true;
            answer = temp;
        }
        return;
    }
    
    int distance = calDistance(cur, target);
    
    if(k < distance + step) return;
    if((k - step - distance) % 2) return;
    
    
    for(int dir = 0; dir < 4; dir++){
        int next_x = cur.x + dx[dir];
        int next_y = cur.y + dy[dir];
        if(inRange(next_x, next_y)){
            temp += moveDir[dir];
            dfs(step + 1, k, {next_x, next_y}, target, flag);
            temp.pop_back();
        }
    }
}

string solution(int _n, int _m, int x, int y, int r, int c, int k) {
    n = _n;
    m = _m;
    int distance = calDistance({x,y}, {r,c});
    bool flag = false;
    
    if(((k - distance) % 2 ) || distance > k) answer = "impossible";
    else dfs(0, k, Point{x, y}, Point{r, c}, flag);
    
    return answer;
}