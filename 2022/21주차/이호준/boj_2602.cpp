/*******************************************************************
Algorithm Study
BAEKJOON 21주차
2602 돌다리 건너기
2022/09/29 이호준
# 아이디어
1. 1차시도 DFS -> 시간초과
2. DP 이해가 필요하다.
*******************************************************************/

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int answer = 0;
// vector<char> paths[2];
// vector<char> masic_roll;

// void dfs(int type, int index, int current_char_index){
//     if(current_char_index == masic_roll.size()){
//         answer++;
//         return;
//     }

//     for(int i = index; i < paths[0].size(); i++){
//         if (paths[0].size() - i < masic_roll.size() - current_char_index)
//             return;
//         if(type){
//             if(paths[0][i] == masic_roll[current_char_index]){
//                 dfs(0, i + 1, current_char_index+1);
//             }
//         }else{
//             if(paths[1][i] == masic_roll[current_char_index]){
//                 dfs(1, i + 1, current_char_index+1);
//             }
//         }
//     }
// }

// int main(void){

//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     string temp;
//     cin >> temp;

//     for(int i = 0; i < temp.size(); i++){
//         masic_roll.push_back(temp[i]);
//     }
//     cin >> temp;
//     int size = temp.size();

//     for(int i =0; i< size; i++){
//         paths[0].push_back(temp[i]);
//     }
//     cin >> temp;
//     for(int i =0; i< size; i++){
//         paths[1].push_back(temp[i]);
//     }

//     dfs(0, 0, 0);
//     dfs(1, 0 ,0);



//     cout << answer;

//     return 0;
// }

#include <iostream>
#include <cstring>
 
using namespace std;
 
int dp[101][2][21];
string Sq, Bridge[2];
 
int solve(int now_idx, int now_b, int sq_idx){
    if(sq_idx == Sq.size()) return 1;
    
    int &ret = dp[now_idx][now_b][sq_idx];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i = now_idx; i < Bridge[0].size(); i++){
        if(Bridge[now_b][i] == Sq[sq_idx]){
            ret += solve(i+1, !now_b, sq_idx+1);
        }
    }
    
    return ret;
}
 
int main(){
    int result = 0;
    cin >> Sq >> Bridge[0] >> Bridge[1];
    
    memset(dp, -1, sizeof(dp));
    
    result += solve(0, 0, 0);   // 악마 먼저
    result += solve(0, 1, 0);   // 천사 먼저
    
    cout << result;
    
    return 0;
}
