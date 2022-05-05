#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v[18];
vector<int> animalV;
bool visited[18][18];
bool visited2[18];
int maxSheep = 0;
int maxCnt = 0;

void dfs(int now, int sheep, int wolf) {
    
    maxCnt = max(maxCnt, sheep);
    
    if (sheep == maxSheep) {
        maxCnt = maxSheep;
        return;
    }
    
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        int nextAnm = animalV[next];
        
        if (visited[next][sheep]) continue;
        
        if (!nextAnm) {
            if (!visited2[next]){
                visited2[next] = 1;
                visited[next][sheep] = 1;
                dfs(next, sheep + 1, wolf);
                visited2[next] = 0;
                visited[next][sheep] = 0;
            }
            else {
                visited[next][sheep] = 1;
                dfs(next, sheep, wolf);
                visited[next][sheep] = 0;
            }
        }
        else {
            if (wolf + 1 >= sheep) continue;
            
            if (!visited2[next]){
                visited2[next] = 1;
                visited[next][sheep] = 1;
                dfs(next, sheep, wolf + 1);
                visited2[next] = 0;
                visited[next][sheep] = 0;
            }
            else {
                visited[next][sheep] = 1;
                dfs(next, sheep, wolf);
                visited[next][sheep] = 0;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for (int i : info) {
        animalV.push_back(i);
        if (!i) maxSheep++;
    }
    
    for (int i = 0; i < edges.size(); i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    visited2[0] = 1;
    visited[0][0] = 1;
    dfs(0, 1, 0);
    
    return maxCnt;

}
