/*******************************************************************
16562 친구비
2022/10/12 이호준
# 아이디어
1. Union-Find
*******************************************************************/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int friends_set[10001];

int find(int x){
    if(x == friends_set[x]){
        return x;
    }else{
        return friends_set[x] = find(friends_set[x]);
    }
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> friend_fee(n + 1, 0);
    for(int i = 1 ; i<= n; i++){
        cin >> friend_fee[i];
    }

    for(int i = 0; i <=n; i++){
        friends_set[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int friend_a = find(a);
        int friend_b = find(b);

        if(friend_fee[friend_a] > friend_fee[friend_b]){
            friends_set[friend_a] = friend_b;
        }else{
            friends_set[friend_b] = friend_a;
        }
    }

    set<int> friend_leader;
    for(int i = 1; i <= n; i++){
        if(i == friends_set[i]){
            friend_leader.insert(i);
        }
    }

    int total_fee = 0;

    for(int leader : friend_leader){
        total_fee += friend_fee[leader];
    }

    if(total_fee > k){
        cout << "Oh no";
    }else{
        cout << total_fee;
    }

    return 0;
}