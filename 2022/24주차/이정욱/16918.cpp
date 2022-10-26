#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int r,c,n,sec;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
char arr[201][201];
vector<pair<int, int>> bomb;

//홀수에 터짐
void go(){
    if(sec % 2){
        for(int i=0;i<bomb.size();i++){
            int x = bomb[i].first;
            int y = bomb[i].second;
            arr[x][y] = '.';
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                arr[nx][ny] = '.';
            }
        }
        bomb.clear();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j] == 'O') bomb.push_back({i,j});
            }
        }
    }else{
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr[i][j] = 'O';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>r>>c>>n;
    for(int i=0;i<r;i++){
        string s; cin>>s;
        for(int j=0;j<c;j++){
            arr[i][j] = s[j];
        }
    }
    for(int i=0;i<n;i++){
        sec++;
        go();
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}
