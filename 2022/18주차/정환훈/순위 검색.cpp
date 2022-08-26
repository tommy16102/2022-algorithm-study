#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    
    map<string, vector<int>> m;
    
    vector<string> qlangs;
    vector<string> qfields;
    vector<string> qexs;
    vector<string> qfoods;
    vector<string> qscores;

    vector<string> ilangs;
    vector<string> ifields;
    vector<string> iexs;
    vector<string> ifoods;
    vector<string> iscores;
    vector<int> answer;
    
    // info문 파싱
    for(int i=0;i<info.size();i++){
        string q = info[i];
        vector<string> words;
        int current = q.find(' ');
        int prev = 0;
        while(current != string::npos){
            words.push_back(q.substr(prev, current - prev));
            prev = current + 1;
            current = q.find(' ', prev);
        }
        words.push_back(q.substr(prev, current - prev));
        
        ilangs.push_back(words[0]);
        ifields.push_back(words[1]);
        iexs.push_back(words[2]);
        ifoods.push_back(words[3]);
        iscores.push_back(words[4]);
        
        string temp[4][2];
        for(int a=0;a<4;a++){
            temp[a][0] = "-";
        }
        for(int a=0;a<4;a++){
            temp[a][1] = words[a];
        }
        // 사용자 정보 key로 하여 map 만들기
        // -를 포함한 key도 +가 되어야 하므로
        for(int a=0;a<2;a++){
            for(int b=0;b<2;b++){
                for(int c=0;c<2;c++){
                    for(int d=0;d<2;d++){
                        string key = temp[0][a] + temp[1][b] + temp[2][c] + temp[3][d];
                        m[key].push_back(stoi(words[4]));
                    }
                }
            }
        }
    }
    
    // 모든 value의 벡터값들 정렬
    for(auto& i : m){
        sort(i.second.begin(), i.second.end());
    }

    // 쿼리문 파싱
    for(int i=0;i<query.size();i++){
        string q = query[i];
        vector<string> words;
        int current = q.find(' ');
        int prev = 0;
        while(current != string::npos){
            words.push_back(q.substr(prev, current - prev));
            prev = current + 1;
            current = q.find(' ', prev);
        }
        words.push_back(q.substr(prev, current - prev));

        qlangs.push_back(words[0]);
        qfields.push_back(words[2]);
        qexs.push_back(words[4]);
        qfoods.push_back(words[6]);
        qscores.push_back(words[7]);
    }

    
    for(int i=0;i<query.size();i++){
        string qlang = qlangs[i];
        string qfield = qfields[i];
        string qex = qexs[i];
        string qfood = qfoods[i];
        string qscore = qscores[i];
        string key = qlang + qfield + qex + qfood;
        vector<int> v = m[key];
        
        //cout << "key : " << key << endl;
        //cout << "================\n";
        //for(int i=0;i<v.size();i++){
        //    cout << v[i] << endl;
        //}
        //cout << "================\n";
        
        // 해당 value로 뽑아낸 벡터에서 query score 이상 값들을 찾아내면 된다.
        int ans = v.end() - lower_bound(v.begin(), v.end(), stoi(qscore));
        answer.push_back(ans);
    }   
    
    
    return answer;
}