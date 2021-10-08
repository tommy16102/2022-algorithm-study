#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>


using namespace std; // 210914

bool cmp(pair<string, int>& a, pair<string, int>& b) { // second 기준으로 오름차순

    return a.second > b.second;
}

bool cmp_value(pair<int, int>& a, pair<int, int>& b) {

    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> answer;
    
    map<string, int> m; // genre -> play 수
    vector<string> sorted; // play 많은 순서대로 genre 정리
    map<string, vector<pair<int, int>>> pl; // genre -> vector of (id, play)

    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i]; // genre -> play 수 정리
        pl[genres[i]].push_back(make_pair(i, plays[i])); // genre -> vector of (id, play) 정리
    }


    vector<pair<string, int>> p(m.begin(), m.end()); // genre -> play 수를 play 수 기준으로 정렬하기 위한 벡터
    sort(p.begin(), p.end(), cmp);

    for (auto iter = p.begin(); iter != p.end(); iter++) {
        sorted.push_back(iter->first); // 정렬된 순서대로 string만 넣어주기
        //cout << iter->first << "  " << iter->second << endl;
    }
    
    for(int i=0;i<sorted.size();i++){ // 각각의 벡터들을 play수 기준으로 정렬해줌
       sort(pl[sorted[i]].begin(), pl[sorted[i]].end(), cmp_value);
    }
    
    for(int i=0;i<sorted.size();i++){
        for(int j=0;j<pl[sorted[i]].size();j++){
     //       cout << pl[sorted[i]][j].first << "  " << pl[sorted[i]][j].second << endl;
        }
    }
    
    for (int i = 0; i < sorted.size(); i++) { 
        string now = sorted[i]; // 현재 장르
        int count = 0; // 최대 2개
        for (int j = 0; j < pl[now].size(); j++) {
            if (count == 2)
                break;
            answer.push_back(pl[now][j].first);
            count++;
        }

    }

    return answer;

}