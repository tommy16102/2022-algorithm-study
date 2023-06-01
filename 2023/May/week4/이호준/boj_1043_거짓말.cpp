/*******************************************************************
Algorithm Study
Baekjoon 1043 거짓말
2023/05/22 이호준
# 아이디어
1. Disjoint Set
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int party[51];

int find(int x){
    if(x == party[x]) return x;
    else return party[x] = find(party[x]);
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> partyInfo(m, vector<int>());

    int truth;
    cin >> truth;

    for(int i = 1; i <= n; ++i){
        party[i] = i;
    }

    int truth_party = 0;
    for(int i = 0; i < truth; ++i){
        int num;
        cin >> num;
        if(truth_party == 0)
            truth_party = num;
        party[num] = truth_party;
    }

    for(int i = 0; i < m; ++i){
        int num;
        cin >> num;
        int new_party = 0;
        for(int j = 0; j < num; ++j){
            int p_num;
            cin >> p_num;
            partyInfo[i].push_back(p_num);
            if(new_party == 0){
                new_party = find(p_num);
            }
            int x = find(p_num);
            party[x] = new_party;
        }
    }

    int answer = m;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < partyInfo[i].size(); j++){
            if(find(partyInfo[i][j]) == find(truth_party)){
                answer--;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}