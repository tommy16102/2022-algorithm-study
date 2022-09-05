#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> pan;

bool check(vector<vector<int>>& key, int y, int x){
    bool ret = true;

    for(int i=y;i<y+m;i++)
        for(int j=x;j<x+m;j++)
            pan[i][j]+=key[i-y][j-x];

    for(int i=m;i<m+n;i++){
        for(int j=m;j<m+n;j++){
            if(pan[i][j]!=1){
                ret=false;
                break;
            }
        }
        if(!ret) break;
    }

    for(int i=y;i<y+m;i++)
        for(int j=x;j<x+m;j++)
            pan[i][j]-=key[i-y][j-x];

    return ret;
}

void rotate(vector<vector<int>>& key){
    vector<vector<int>> temp(m,vector<int>(m));

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            temp[i][j] = key[j][m-i-1];

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            key[i][j] = temp[i][j];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    m = key.size();
    n = lock.size();

    pan = vector<vector<int>>(2*m+n,vector<int>(2*m+n));

    for(int i=m;i<m+n;i++)
        for(int j=m;j<m+n;j++)
            pan[i][j]=lock[i-m][j-m];

    for(int i=0;i<n+m;i++){
        for(int j=0;j<n+m;j++){
            for(int k=0;k<4;k++){
                rotate(key);
                if(check(key,i,j)){
                    answer = true;
                    break;
                }
            }
            if(answer) break;
        }
        if(answer) break;
    }

    return answer;
}