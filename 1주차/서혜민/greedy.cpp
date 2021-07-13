#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer += n - lost.size();

    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0;i < lost.size();i++) {
        for (int j = 0;j < reserve.size();j++) {
            if (lost[i] == reserve[j]) {
                answer++;
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--; j--;
                break;
            }
        }
    }

    bool checked[31]{ 0, };
    for (int i = 0;i < lost.size();i++) {
        for (int j = 0;j < reserve.size();j++) {
            if (lost[i] == reserve[j] + 1 && !checked[reserve[j]]) {
                answer++;
                checked[reserve[j]] = 1;
                break;
            }
            else if (lost[i] == reserve[j] - 1 && !checked[reserve[j]]) {
                answer++;
                checked[reserve[j]] = 1;
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector <int> a = { 2,4, };
    vector <int> a1 = { 1,3,5 };
    cout << solution(5, a, a1) << endl;
    vector <int> b = { 2,4, };
    vector <int> b1 = { 3 };
    cout << solution(5, b, b1) << endl;
    vector <int> c = { 3 };
    vector <int> c1 = { 1 };
    cout << solution(3, c, c1) << endl;
}

