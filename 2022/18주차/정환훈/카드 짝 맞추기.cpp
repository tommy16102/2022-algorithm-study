#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int used[7];
int sel[7];
int sel2[7];
int ans = 987654321;
pair<pair<int,int>, pair<int,int>> v[7];
vector<int> myAry = {0,0,0,0,0,0};
vector<int> ary = {1,2,3,4,5,6};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};
vector<vector<int>> b;
vector<vector<int>> save;
pair<int,int> start;

// from에서 to까지 가는 데 cost 구하는 함수
int getCost(pair<int,int> from, pair<int,int> to){
    int fromY = from.first; int fromX = from.second;
    int toY = to.first; int toX = to.second;
    // 없는 카드는 넘기고
    if(fromY == -1 || fromX == -1 || toY == -1 || toX == -1) return 0;
    // 같으면 0
    if(fromY == toY && fromX == toX) return 0;
    bool v[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            v[i][j] = false;
        }
    }
    
    queue<pair<pair<int,int>, int>> q;
    vector<pair<int, pair<int,int>>> vp;
    int cost = 0;
    q.push({{fromY, fromX}, cost});
    v[fromY][fromX] = true;
    vp.push_back({99999, {100, 100}});
    
    // bfs로 찾기
    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int y = now.first; int x = now.second;
        v[y][x] = true;
        int nowCost = q.front().second;
        if(y == toY && x == toX){
            return nowCost;
            vp.push_back({nowCost,{y, x}});
        }
        q.pop();
        
        // 상하좌우 이동
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny>=0 && ny<4 && nx>=0 && nx<4 && !v[ny][nx]){
                v[ny][nx] = true;
                q.push({{ny, nx}, nowCost+1});
            }
        }
        
        // ctrl + 상하좌우 이동
        // 나 근데 왜 여기서 방문처리하면 틀리는지 잘 모르겠음
        for(int k=y;k>=0;k--){
            if(k != y && b[k][x] != 0){
                    q.push({{k, x}, nowCost+1});
                    break;
                
            }
            if(k==0){
                if(y!=0){
                    q.push({{k, x}, nowCost+1});
                    break;
                }
            }
        }                
    
        for(int k=y;k<=3;k++){
            if(k != y && b[k][x] != 0){

                    q.push({{k, x}, nowCost+1});
                    break;
                
            }
            if(k==3){
                if(y!=3){
                    q.push({{k, x}, nowCost+1});
                    break;
                }
            }
        }   
    
        for(int k=x;k>=0;k--){
            if(k != x && b[y][k] != 0){
                    q.push({{y, k}, nowCost+1});
                    break;
                
            }
            if(k==0){
                if(x!=0){
                    q.push({{y, k}, nowCost+1});
                    break;
                }
            }
        }   
    
        for(int k=x;k<=3;k++){
            if(k != x && b[y][k] != 0){
                    q.push({{y, k}, nowCost+1});
                    break;
                
            }
            if(k==3){
                if(x!= 3){
                    q.push({{y, k}, nowCost+1});
                    break;
                }
            }
        }           
    }
    
    sort(vp.begin(), vp.end());
    return vp[0].first;
}

void solve(vector<int> order, vector<int> fb){
    // 3. 공략 순서와 앞뒤 선택을 받아서 각각의 경우 처리
    int t = 0;
    pair<int,int> nowPos = start;
    for(int i=0;i<order.size();i++){
        int now = order[i];
        pair<int,int> from = v[now].first;
        pair<int,int> to = v[now].second;
        if(from.first == -1 || from.second == -1 || to.first == -1 || to.second == -1) continue;
        // fb[now] == 0 start->from->to
        // start->from
        // enter
        // from->to
        // enter
        if(fb[now] == 0){
            int cost = 0;
            int n2fCost = getCost(nowPos, from);
            cost += n2fCost;
            cost++; // enter
            b[from.first][from.second] = 0; // from 카드 닫기
            int n2tCost = getCost(from, to);
            cost += n2tCost;
            cost++; // enter
            b[to.first][to.second] = 0; // to 카드 닫기
            t += cost;
            nowPos = to; // 위치 이동
        }
        // fb[now] == 1 start->to->from
        else if(fb[now] == 1){
            int cost = 0;
            int n2tCost = getCost(nowPos, to);
            cost += n2tCost;
            cost++; // enter
            b[to.first][to.second] = 0;
            int n2fCost = getCost(to, from);
            cost += n2fCost;
            cost++;// enter
            b[from.first][from.second] = 0;
            t += cost;
            nowPos = from;
        }
        else ans = -12345; // 있어서 안돼         
    }
    
    ans = min(t, ans);
}

string toBinary(int dec){
    string bin = "";
    while(dec > 0){
        if(dec % 2 == 0){
            bin += "0";
        }
        else bin += "1";
        dec /= 2;
    }
    while(bin.size() < 6)
        bin = bin + "0";

    reverse(bin.begin(), bin.end());
    bin = "9" + bin;
    return bin;
}

void nPr(int depth, int n, int r){
    
    if(depth == 6){
        // 2. 각각의 카드에 대해서 0/1로 나눠 어떤 쪽을 먼저 선택할지 완전탐색
        // ex) ary[3] = 0이면 3번 카드 앞쪽 먼저, 1이면 3번 카드 뒷쪽 먼저
        for(int i=0;i<64;i++){
            b = save;
            string fb = toBinary(i);
            vector<int> fbAry = {-1,0,0,0,0,0,0};
            for(int k=1;k<=6;k++){
                fbAry[k] = fb[k] - '0';
            }
            solve(myAry, fbAry);
        }        
        return;
    }
    
    for(int i=0;i<n;i++){
        if(sel[i]) continue;
        sel[i] = true;
        myAry[depth] = ary[i];
        nPr(depth + 1, n, r);
        sel[i] = false;
    }
}


int solution(vector<vector<int>> board, int r, int c) {
    start = {r, c};
    save = board;
    b = board;
    // 없는 카드의 좌표는 -1,-1의 짝으로
    for(int i=0;i<7;i++){
        v[i] ={{-1,-1}, {-1,-1}};
    }
    
    // 카드 좌표 지정 = 1번 카드 좌표 = v[1].first, v[1].second
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            int card = board[i][j];
            if(card != 0){
                if(used[card] == 0){
                    v[card].first = {i, j};
                    used[card] = 1;
                }
                else if(used[card] == 1){
                    v[card].second = {i, j};
                }
            }                
        }
    }    
    // 1. 123456을 nPr 돌려서 모든 공략 순서를 완전 탐색
    nPr(0, 6, 6);
   
    return ans;
}

