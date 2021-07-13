#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> res;
    for (int i = 0;i < progresses.size();i++) {
        int count = 0;
        while (progresses[i] < 100) {
            progresses[i] += speeds[i];
            count++;
        }
        res.push_back(count);
    }
    vector<int> answer;
    vector<int> result;
    
    int max = -1;
    for (int i = 0;i < res.size();i++) {
        if (i == 0) {
            max = res[i];
        }
        else if (max < res[i]) {
            max = res[i];
            answer.push_back(result.size());
            result.clear();
        }
        result.push_back(res[i]);
        if (i == res.size() - 1) {
            answer.push_back(result.size());
        }
    }
    return answer;
   
}

int main() {
    vector<int> p = { 93, 30, 55 };
    vector<int> s = { 1, 30, 5 };
    vector<int> so = solution(p, s);
    for (int i = 0;i < so.size();i++) {
        cout << so[i] << ' ';
    }
}