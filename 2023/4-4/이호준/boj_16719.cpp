/*******************************************************************
Algorithm Study
Baekjoon 16719 ZOAC
2023/04/26 이호준
# 아이디어
1. BruteForce
2. 어렵다.
*******************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;
 

bool visited[MAX];

int main(void){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;

    cin >> input;

    for (int i = 0; i < input.size(); i++){

        vector<pair<string, int>> v;

        for (int j = 0; j < input.size(); j++){
            if (!visited[j]){
                string candidate;
                for (int k = 0; k < input.size(); k++)
                    if (j == k || visited[k])
                        candidate += input[k];
                v.push_back({ candidate, j });
            }
        }
        sort(v.begin(), v.end());
        cout << v[0].first << "\n";
        visited[v[0].second] = true;
    }

    return 0;
}