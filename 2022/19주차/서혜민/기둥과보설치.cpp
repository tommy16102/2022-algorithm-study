#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[101][101][2];
int len;

bool canBuildKd(int x, int y) {
    if (y == 0 || (x > 0 && arr[x - 1][y][1]) || (x < len && arr[x][y][1]) || (y > 0 && arr[x][y - 1][0])) return true;
    return false;
}

bool canBuildBo(int x, int y) {
    if (y > 0 && (arr[x][y-1][0] == 1 || (x < len && arr[x+1][y-1][0] == 1))) return true;
    if (x > 0 && x < len && arr[x - 1][y][1] == 1 && arr[x + 1][y][1] == 1 ) return true;
    return false;
}
        
void buildKd(int x, int y) {
    if (canBuildKd(x, y)) arr[x][y][0] = 1;
}

void buildBo(int x, int y) {
     if (canBuildBo(x, y)) arr[x][y][1] = 1;
}

bool checkKd(int x, int y) {
    if (y < len - 1 && arr[x][y + 1][0] == 1) {
        arr[x][y][0] = 0;
        bool res = canBuildKd(x, y+1);
        arr[x][y][0] = 1;
        if (!res) return res;
    }
    if (y < len && x < len && arr[x][y+1][1] == 1) {
        arr[x][y][0] = 0;
        bool res = canBuildBo(x, y+1);
        arr[x][y][0] = 1;
        if (!res) return res;
    }
    if (y < len && x > 0 && arr[x-1][y+1][1] == 1) {
        arr[x][y][0] = 0;
        bool res = canBuildBo(x-1, y+1);
        arr[x][y][0] = 1;
        if (!res) return res;
    }
    return true;
}

bool checkBo(int x, int y) {
    if (y < len && arr[x][y][0] == 1) {
        arr[x][y][1] = 0;
        bool res = canBuildKd(x, y);
        arr[x][y][1] = 1;
        if (!res) return res;
    }
    if (y < len && arr[x+1][y][0] == 1) {
        arr[x][y][1] = 0;
        bool res = canBuildKd(x+1, y);
        arr[x][y][1] = 1;
        if (!res) return res;
    }
    if (x > 0 && arr[x-1][y][1] == 1) {
        arr[x][y][1] = 0;
        bool res = canBuildBo(x-1, y);
        arr[x][y][1] = 1;
        if (!res) return res;
    }
     if (x < len - 1 && arr[x+1][y][1] == 1) {
        arr[x][y][1] = 0;
        bool res = canBuildBo(x+1, y);
        arr[x][y][1] = 1;
        if (!res) return res;
    }
    return true;
}

void removeKd(int x, int y) {
    bool canRemove = checkKd(x, y);
    if (canRemove) arr[x][y][0] = 0;
}

void removeBo(int x, int y) {
    bool canRemove = checkBo(x, y);
    if (canRemove) arr[x][y][1] = 0;
}

void build(vector<int> v) {
    int x = v[0];
    int y = v[1];
    int frame = v[2];
    int work = v[3];
    if (work == 1) {
        if (frame == 0) buildKd(x, y);
        else buildBo(x, y);
    }
    else {
        if (frame == 0) removeKd(x, y);
        else removeBo(x, y);
    }
}

vector<vector<int>> calc() {
    vector<vector<int>> answer;
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {\
            if (arr[i][j][0]) answer.push_back({i, j, 0});
            if (arr[i][j][1]) answer.push_back({i, j, 1});
        }
    }
    return answer;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    len = n;
    for (int i = 0; i < build_frame.size(); i++) {
        build(build_frame[i]);
    }
    return calc();
}