/*******************************************************************
Algorithm Study
Baekjoon 1132 합
2023/05/11 이호준
# 아이디어
1. Greedy
원칙 : 길이가 긴 string의 앞자리에 높은 숫자를 준다.
예외 : 0이 될 수 없는 수
*******************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define SIZE 10

using namespace std;

typedef long long ll;

bool zeroCandidate[SIZE];
ll alphabetCount[SIZE];
int alphabetValue[SIZE];

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    vector<string> inputs(n, "");
    fill(&zeroCandidate[0], &zeroCandidate[SIZE], true);
    for(int i = 0; i < n; i++){
        cin >> s;
        inputs[i] = s;
        zeroCandidate[s[0] - 'A'] = false;
        ll temp = 1;
        for(int j = s.size() - 1; j >= 0; --j){
            alphabetCount[s[j] - 'A'] += temp;
            temp *= 10;
        }
    }

    vector<pair<ll, int>> candidates;
    for(int i = 0; i < SIZE; ++i){
        if(alphabetCount[i] > 0){
            candidates.push_back({alphabetCount[i], i});
        }
    }

    sort(candidates.begin(), candidates.end(), greater<>());

    if(candidates.size()== SIZE && !zeroCandidate[candidates.back().second]){
        int index = candidates.size() - 1;
        for(;;--index)
            if(zeroCandidate[candidates[index].second])
                break;
        pair<ll, int> zero = candidates[index];
        for(int i = index; i < candidates.size() - 1; ++i){
            candidates[i].second = candidates[i + 1].second;
        }
        candidates[candidates.size() - 1].second = zero.second;
    }

    for(int i = 0; i < candidates.size(); ++i){
        alphabetValue[candidates[i].second] = 9 - i;
    }

    ll answer = 0;
    for(int i = 0; i < inputs.size(); i++){
        string temp = "";
        for(int j = 0; j < inputs[i].size(); j++){
            temp += to_string(alphabetValue[inputs[i][j] - 'A']);
        }
        answer += stoll(temp);
    }

    cout << answer;

    return 0;
}