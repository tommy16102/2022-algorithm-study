#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int ary[10] = {0,1,2,3,4,5,6,7,8,9};
int on[10];
int sel[10];
int myAry[10];
int ans;
int rowSize;
vector<vector<string>> rel;
set<set<int>> clearSet;

bool subsetTest(set<int> big, set<int> small){
    // big의 subset 안에 small 있는지    
    vector<int> target;
    for(auto v : big){
        target.push_back(v);
    }    
    for(int i=0; i< (1<<big.size()) ;i++){
        set<int> test;
        for(int j=0;j<big.size();j++){
            if(i & (1<<j)){
                test.insert(target[j]);
            }
        }
        if(test == small) return true;
    }
    return false;
}

void nCr(int depth, int id, int n, int r){
    if(depth == r){
        set<string> s;
        for(int i=0;i<rel.size();i++){
            string test = "";
            for(int j=0;j<r;j++){
                test += rel[i][myAry[j]];
            }
            s.insert(test);           
        }
        if(s.size() == rowSize){
            set<int> temp;
            for(int i=0;i<r;i++){
                temp.insert(myAry[i]);
            }
            for(auto nowSet : clearSet){
                // if nowSet의 subSet == temp return;
                if(subsetTest(temp, nowSet))
                    return;
            }
            clearSet.insert(temp);    
            ans++;            
        }
            
        return;
    }
    
    for(int i=id;i<n;i++){
        if(sel[i])
            continue;
        sel[i] = true;
        myAry[depth] = ary[i];
        nCr(depth + 1, i, n, r);
        sel[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    rel = relation;
    int row = relation.size();
    int columns = relation[0].size();
    rowSize = row;
    for(int i=1;i<=columns;i++){
        nCr(0, 0, columns, i);
    }
    
    return ans;
}
