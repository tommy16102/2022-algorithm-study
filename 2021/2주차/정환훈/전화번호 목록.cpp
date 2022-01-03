#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07/13

    기본 아이디어 : 주어진 전화번호를 정렬시킨다
    i -> 전화번호(string)인 map을 만든다
    i번째부터 차근차근 j번째의 substr과 비교한다

    의문점 : if (map[j].size() == temp.size()) break;
    이거하나 넣었다고 성능이슈 해결?
    이건 그냥 숫자 길이 같은애들만 비교 안하는거 같은데 된다니까 뭐...

*/

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<int, string> map;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size(); i++) {
        map.insert(std::make_pair(i, phone_book[i]));
    }


    for (int i = 0; i < phone_book.size(); i++) {
        string temp = map[i];

        for (int j = i + 1; j < phone_book.size(); j++) {
            if (map[j].size() == temp.size()) break;
            string temp2 = map[j].substr(0, temp.size());

            if (temp == temp2) {
                answer = false;
                return answer;
            }
        }

    }
    return answer;
}