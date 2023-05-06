#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<int, int> p;
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
string board[51][51];
void merge(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    p[pb] = p[pa];
}
const string EMPTY = "!@#$%^&";
vector<string> solution(vector<string> commands) {
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            p[i*51+j] = i*51+j;
            board[i][j] = EMPTY;
        }
    }
    vector<string> answer;
    for(string cmd : commands){
        vector<string> split;
        int prev = 0; int cur = cmd.find(' ');
        while(cur != string::npos){
            string s = cmd.substr(prev, cur-prev);
            split.push_back(s);
            prev = cur + 1;
            cur = cmd.find(' ', prev);
        }
        split.push_back(cmd.substr(prev));
        if(split[0] == "UPDATE"){
            if(split.size() == 4){
                int r = stoi(split[1]);
                int c = stoi(split[2]);
                string value = split[3];
                for(int i=0;i<51;i++){
                    for(int j=0;j<51;j++){
                        if(find(r*51+c) == find(i*51+j)){
                            board[i][j] = value;
                        }
                    }
                }                
            }
            else if(split.size() == 3){
                string value1 = split[1];
                string value2 = split[2];
                    for(int i=0;i<51;i++){
                        for(int j=0;j<51;j++){
                            if(board[i][j] == value1){
                                board[i][j] = value2;
                            }
                        }
                }
            }
        }
        else if(split[0] == "MERGE"){
            int r1 = stoi(split[1]);
            int c1 = stoi(split[2]);
            int r2 = stoi(split[3]);
            int c2 = stoi(split[4]);
            merge(51*r1+c1, 51*r2+c2);
            string value = EMPTY;
            if(board[r1][c1] == EMPTY && board[r2][c2] != EMPTY){
                value = board[r2][c2];
            }
            else if(board[r1][c1] != EMPTY){
                value = board[r1][c1];
            }
            for(int i=0;i<51;i++){
                for(int j=0;j<51;j++){
                    if(find(51*i+j) == find(51*r1+c1)){
                        board[i][j] = value;
                    }
                }
            }
        }
        else if(split[0] == "UNMERGE"){
            int r = stoi(split[1]);
            int c = stoi(split[2]);
            vector<pair<int,int>> v;
            string temp = board[r][c];
            for(int i=0;i<51;i++){
                for(int j=0;j<51;j++){
                    if(find(51*i+j) == find(r*51+c)){
                        v.push_back({i, j});
                    }
                }
            }
            for(auto e : v){
                p[e.first*51+e.second] = e.first*51+e.second;
                board[e.first][e.second] = EMPTY;
            }
            if(temp != " ")
                board[r][c] = temp;
        }
        else if(split[0] == "PRINT"){
            int r = stoi(split[1]);
            int c = stoi(split[2]);
            if(board[r][c] == EMPTY) {answer.push_back("EMPTY");}
            else answer.push_back(board[r][c]);
        }
        
    }
    return answer;
}
