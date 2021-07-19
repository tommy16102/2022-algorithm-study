#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.07.12 서혜민

해당 코멘드의 몇번째부터 몇번째까지를 나타내는 수를 추출해서,
그 수를 정렬을 시킨 뒤 몇번째의 수를 벡터에 넣어주면 된다.

*/

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> result;
    vector<int> answer;
    for (int i = 0;i < commands.size();i++) {
        int start = commands[i][0];
        int end = commands[i][1];
        int point = commands[i][2];
        for (int j = start;j <= end;j++) {
            result.push_back(array[j - 1]);
        }
        sort(result.begin(), result.end());
        for (int k = 0;k < result.size();k++) {
            cout << result[k] << ' ';
        }
        cout << endl;
        answer.push_back(result[point - 1]);
        result.clear();
    }
    return answer;
}

int main() {
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3,},{4,4,1},{1,7,3} };

    vector<int> result = solution(array, commands);
    for (int i = 0;i < result.size();i++) cout << result[i] << ' ';
}