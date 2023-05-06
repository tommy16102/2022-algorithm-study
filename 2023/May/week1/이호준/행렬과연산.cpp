/*******************************************************************
Algorithm Study
2022 KAKAO TECH INTERNSHIP 행렬과 연산
2023/05/06 이호준
# 아이디어
1. rotate를 그냥 순수 연산으로하면 시간초과 -> 무슨 다른 방법이 존재한다.
Deque로 행과 열을 분해해서 보면 Rotate를 처리할 수 있다.
=> 가장자리 2개 열과 첫번째행, 마지막 행 (원래 행렬에서 첫번째 열과 마지막 열을 제외한)을 기준으로 행렬을 분리하면 된다.
// 정답코드와 해설을 참고함. (실전에서 풀기 굉장히 어려울 것 같다.)
*******************************************************************/
#include <vector>
#include <deque>
#include <string>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int r = rc.size();
    int c = rc[0].size();
    deque<int> col1, col2;
    for(int i = 0; i < r; i++){
        col1.push_back(rc[i][0]);
        col2.push_back(rc[i][c-1]);
    }

    deque<int> rows[r];
    for(int i = 0; i < r; i++)
        for(int j = 1; j <= c-2; j++)
            rows[i].push_back(rc[i][j]);
    
    int topRowIndex = 0; // topRowIndex
    for(auto op : operations){
        if(op == "ShiftRow"){
            col1.push_front(col1.back());
            col1.pop_back();
            col2.push_front(col2.back());
            col2.pop_back();
            topRowIndex--;
            if(topRowIndex == -1) 
                topRowIndex = r-1;
        }
        else{ // Rotate
            rows[topRowIndex].push_front(col1.front());
            col1.pop_front();
            
            col2.push_front(rows[topRowIndex].back());
            rows[topRowIndex].pop_back();
            
            rows[(topRowIndex+r-1)%r].push_back(col2.back());
            col2.pop_back();
            
            col1.push_back(rows[(topRowIndex+r-1)%r].front());
            rows[(topRowIndex+r-1)%r].pop_front();
        }
    }
    
    
    vector<vector<int>> ret(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        ret[i][0] = col1[i];
        for(int j = 1; j <= c-2; j++)
            ret[i][j] = rows[(i + topRowIndex) % r][j-1];
        ret[i][c-1] = col2[i];
    }
    return ret;
}