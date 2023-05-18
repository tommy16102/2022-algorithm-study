/*******************************************************************
Algorithm Study
Baekjoon 21939 문제추천시스템
2023/05/18 이호준
# 아이디어
1. PQ
*******************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solved[100001];

struct compare{
    
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.second == b.second){
            return a.first < b.first;
        }else{
            return a.second < b.second;
        }
    }
};

struct compare2{
    
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.second == b.second){
            return a.first > b.first;
        }else{
            return a.second > b.second;
        }
    }
};

void getRecommand(priority_queue<pair<int,int>> q){
    while(!q.empty()){
        int problemNum = q.top().first;
        if(solved[problemNum] == q.top().second){
            cout << q.top().first << "\n";
            break;
        }else{
            q.pop();
        }
    }
}


int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare2> pq2;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int problemNum, problemLevel;
        cin >> problemNum >> problemLevel;
        pq1.push({problemNum, problemLevel});
        pq2.push({problemNum, problemLevel});
        solved[problemNum] = problemLevel;
    }
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string command;
        cin >> command;
        if(command == "add"){
            int problemNum, problemLevel;
            cin >> problemNum >> problemLevel;
            pq1.push({problemNum, problemLevel});
            pq2.push({problemNum, problemLevel});
            solved[problemNum] = problemLevel;
        }else if (command == "solved"){
            int problemNum;
            cin >> problemNum;
            solved[problemNum] = -1;
        }else{
            int a;
            cin >> a;
            if(a == 1){
                while(!pq1.empty()){
                    int problemNum = pq1.top().first;
                    if(solved[problemNum] == pq1.top().second){
                        cout << pq1.top().first << "\n";
                        break;
                    }else{
                        pq1.pop();
                    }
                }
            }else{
                while(!pq2.empty()){
                    int problemNum = pq2.top().first;
                    if(solved[problemNum] == pq2.top().second){
                        cout << pq2.top().first << "\n";
                        break;
                    }else{
                        pq2.pop();
                    }
                }
            }
        }
    }
    return 0;
}