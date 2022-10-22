/*******************************************************************
2002 추월
2022/10/22 이호준
# 아이디어
1. 구현
*******************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> inputs(n, " ");
    unordered_map<string, int> exit;

    for(int i = 0; i<n; i++){
        cin >> inputs[i];
    }
    for(int i = 0; i<n; i++){
        string temp;
        cin >> temp;
        exit.insert({temp, i});
    }
    int current_index = 0;
    int answer = 0;
    for(int i = 0; i < n; i++){
        int index = exit[inputs[i]]; 
        if(index > current_index){
            answer += (index - current_index);
            current_index = index + 1;
        }else if (index == current_index){
            current_index++;
        }
        if(current_index >= n)
            break;
    }

    cout << answer;

    return 0;
}