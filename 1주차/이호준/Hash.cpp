/**
 * Algorithm STudy
 * Programmers 코딩테스트 고득점 Kit
 * Hash / 완주하지 못한 선수
 * 2021 / 07 / 12  이호준
 * 
 * participant정보를 이용해 multimap을 생성
 * competion을 탐색하면서 multimap에서 해당 원소를 찾아 있으면 삭제
 * 찾지 못하면 완주하지 못한 사람이므로 answer return
 * completion이 participant보다 1명 많으므로
 * completion의 탐색이 끝나고 남은 1명이 answer
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_multimap<string, int> member;
    int count = 0;
    // 참가자 전체 명단을 가진 multimap 생성
    for (auto &a : participant)
    {
        member.insert(make_pair(a, count++));
    }
    // 완주자명단에서 없는 사람 찾기
    // 있으면 명단에서 삭제
    // 없으면 해당 인원이 정답
    // 탐색끝난 후 남은 사람이 정답
    for (vector<string>::iterator i = completion.begin(); i != completion.end(); i++)
    {
        if (member.find(*i) != member.end())
        {
            member.erase(member.find(*i));
        }
        else
        {
            answer = *i;
            return answer;
        }
    }
    answer = member.begin()->first;
    return answer;
}