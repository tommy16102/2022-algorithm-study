#include <string>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> buildings;

bool check(){
    
    for(auto b : buildings){
        int x = b[0]; int y = b[1]; int type = b[2];
        if(type == 0){ // 기둥
            // 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
            if(y == 0) continue;
            vector<vector<int>> pre = { {x, y, 1}, {x-1, y, 1}, {x, y-1, 0}};
            if(buildings.find(pre[0]) != buildings.end() ||
               buildings.find(pre[1]) != buildings.end() || 
               buildings.find(pre[2]) != buildings.end()) continue;            
            return false;
        }
        else{ // 보
            // 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
            vector<vector<int>> pre = { {x, y-1, 0}, {x+1, y-1, 0}, {x+1, y, 1}, {x-1, y, 1}};
            if(buildings.find(pre[0]) != buildings.end() ||
               buildings.find(pre[1]) != buildings.end() || 
               (buildings.find(pre[2]) != buildings.end() && buildings.find(pre[3]) != buildings.end())) 
                continue;
            return false;
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(vector<int> b : build_frame){
        int cmd = b[3];
        vector<int> t = {b[0], b[1], b[2]};
        if(cmd == 0){ // 삭제
            buildings.erase(t);
            if(!check()){
                buildings.insert(t);
            }
        }
        else{ // 설치
            buildings.insert(t);
            if(!check()){
                buildings.erase(t);
            }
        }
    }
    
    for(auto &v : buildings){
        answer.push_back(v);
    }
    
    return answer;
}
