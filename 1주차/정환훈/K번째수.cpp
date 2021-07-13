#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    푼 사람 : 정환훈    푼 날짜 : 2021/07

    기본 아이디어 : 문제에서 주어진 조건대로 한 후, 옮겨서 sort.

*/

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;


    for (int l = 0; l < commands.size(); l++) {

        int i = commands[l][0];
        int j = commands[l][1];
        int k = commands[l][2];

        vector<int> sorted(j - i + 1, 0);
        for (int x = 0; x <= j - i; x++) {
            sorted[x] = array[x + i - 1];
        }
        sort(sorted.begin(), sorted.end());
        
        answer.push_back(sorted[k - 1]);
    }

    return answer;
}