/*******************************************************************
1092 배
2022/10/11 이호준
# 아이디어
1. Greedy
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> crain(n, 0);
    for(int i = 0; i< n; i++){
        cin >> crain[i];
    }
    sort(crain.begin(), crain.end());
    int m;
    cin >> m;

    vector<int> boxes(m, 0);
    for(int i =0; i< m; i++){
        cin >> boxes[i];
    }
    sort(boxes.begin(), boxes.end());

    if(boxes.back() > crain.back()){
        cout << -1;
        return 0;
    }

    int times = 0;

    while(!boxes.empty()){
        times++;
        for(int i = crain.size() - 1; i >=0; i--){
            for(int j = boxes.size() - 1; j >=0; j--){
                if(crain[i] >= boxes[j]){
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
    }

    cout << times;

    return 0;
}