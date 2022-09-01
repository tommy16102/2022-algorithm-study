/*******************************************************************
Algorithm Study
2021 Kakao Blind
카드 짝 맞추기 level 3
2022/08/31 이호준
# 아이디어
1. BFS + 조합 구현문제
*******************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<int> card;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int answer = 0x3f3f3f3f;
int r,c;

int bfs(int dest){
    bool check[4][4] = {0, };
    queue<pair<pair<int,int>,int>> q;
    q.push({{r,c},0});
    check[r][c] = true;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(board[x][y] == dest){
            board[x][y] = 0;
            r = x, c = y;
            return cnt+1;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
                continue;
            if(!check[nx][ny]){
                check[nx][ny] = true;
                q.push({{nx,ny},cnt+1});
            }
        }
        for(int i=0;i<4;i++){
            int nx = x;
            int ny = y;
           	while(nx+dx[i]>=0&&ny+dy[i]>=0&&nx+dx[i]<4&&ny+dy[i]<4){
                nx += dx[i];
                ny += dy[i];
                if(board[nx][ny])
                    break;
            } 
            if(!check[nx][ny]){
                check[nx][ny] = true;
                q.push({{nx,ny},cnt+1});
            }
        }
    }
}

int solution(vector<vector<int>> b, int rr, int cc) {
    bool card_check[7] = {0,};
    for(int i=0;i<b.size();i++)
        for(int j=0;j<b[i].size();j++)
            if(b[i][j])
                card_check[b[i][j]] = true;
    for(int i=1;i<7;i++)
        if(card_check[i])
            card.push_back(i);
    do{
        board = b;
        r = rr, c = cc;
        int tmp = 0;
        for(int i=0;i<card.size();i++){
            tmp += bfs(card[i]);
            tmp += bfs(card[i]);
        }
        answer = min(answer,tmp);
    }while(next_permutation(card.begin(),card.end()));
    return answer;
}