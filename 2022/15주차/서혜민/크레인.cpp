#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int sero = board.size();
    int garo = board[0].size();
    int ans = 0;
    
    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i] - 1;
        for(int j = 0; j < sero; j++){
            int now = board[j][move];
            if (now) {
                
                if (!s.empty()){
                    if (s.top() == now){
                        s.pop();
                        ans+=2;
                    }
                    else s.push(now);
                }
                else {
                    s.push(now);
                }
                board[j][move] = 0;
                break;
            }
        }
    }
    return ans;
}