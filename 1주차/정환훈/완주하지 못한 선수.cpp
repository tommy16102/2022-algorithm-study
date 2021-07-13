#include <string>
#include <vector>
#include <map>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : map을 통해 참가자->참가자 수가 매칭되도록 만들고
    거기서 map[완주자 이름]--을 해준다.
    이제 map 값이 0보다 큰 선수가 완주하지 못한 선수다.

*/

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";

    map<string, int> map;

    for (int i = 0; i < participant.size(); i++) {
        map.insert(pair<string, int>(participant[i], 0));
    }


    for (int i = 0; i < participant.size(); i++) {
        map[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); i++) {
        map[completion[i]]--;
    }


    for (int i = 0; i < completion.size(); i++) {        

        if (map[participant[i]] > 0) {
            answer = participant[i];
            return answer;
        }

    }


    return answer;
}