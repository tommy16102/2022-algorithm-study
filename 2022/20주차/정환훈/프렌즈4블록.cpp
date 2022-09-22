#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;
int gm;
int gn;
char b[32][32];

int del(){
    char b2[32][32];  
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            b2[i][j] = 'o';
        }
    }
    
    for(int i=0;i<gm;i++){
        for(int j=0;j<gn;j++){
            if(i+1 < gm && j+1 < gn){
                if(b[i][j] != 'x' && b[i][j] == b[i+1][j] 
                   && b[i][j] == b[i][j+1] && b[i][j] == b[i+1][j+1]){
                    b2[i][j] = 'x'; b2[i+1][j] = 'x'; b2[i][j+1] = 'x'; b2[i+1][j+1] = 'x';
                    //cout << "i : " << i << ", j : " << j << endl;
                }
            }
        }
    }
    
    int x = 0;
    for(int i=0;i<gm;i++){
        for(int j=0;j<gn;j++){
            if(b2[i][j] == 'x'){
                b[i][j] = b2[i][j];
                x++;
            }
        }
    }
    ans += x;    
    return x;
}


void go(){
    for(int i=gm-1;i>=0;i--){
        for(int j=0;j<gn;j++){
            if(b[i][j] != 'x'){
                int k = i;
                while(k+1<gm && b[k+1][j] == 'x'){
                    k++;
                }
                if(k!=i){ 
                    b[k][j] = b[i][j];
                    b[i][j] = 'x';
                }
            }                
        }
    }
}

void print(){
    for(int i=0;i<gm;i++){
        for(int j=0;j<gn;j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << "======================\n";
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    gm = m; gn = n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[i][j] = board[i][j];
        }
    }
    

    for(int i=0;i<1000;i++){
        del();
        go();
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j] == 'x')
                answer++;
        }
    }
    return answer;
}
