/*******************************************************************
15961 회전초밥
2022/10/18 이호준
# 아이디어
1. 투포인터
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int visited[3001];

int main(void) {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> plates(n, 0);

    for(int i = 0; i< n; i++){
        cin >> plates[i];
    }

    for(int i = 0; i < k - 1; i++){
        plates.push_back(plates[i]);
    }

    int answer = 0;

    for(int i = 0; i< k; i++){
        int currentPlate = plates[i];
        if(!visited[currentPlate]){
            answer++;
        }
        visited[currentPlate]++;
    }
    //cout << answer << "\n";

    int left = 0;
    int current_value = answer;
    for(int i = k; i < plates.size(); i++){
        int removePlate = plates[left++];
        int checkPlate = plates[i];

        visited[removePlate]--;

        if(!visited[removePlate])
            current_value--;

        if(!visited[checkPlate]){
            current_value++;
        }
        //cout << removePlate << " " << checkPlate << " " << current_value << " " << visited[c] <<"\n";
        visited[checkPlate]++;
        if(!visited[c]){
            answer = max(answer, current_value + 1);
        }else{
            answer = max(answer, current_value);
        }
    }

    cout << answer;

    return 0;
}