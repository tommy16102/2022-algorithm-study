#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.07.12 서혜민

1.  체육복을 입을 수 있는 사람은 일단 전체 학생 중, 체육복을 잃어버리지 않은 학생이므로 이를 먼저
    answer에 더해준다.
2.  잃어버린 사람을 나타내는 벡터 lost와 여분이 있는 사람을 나타내는 벡터 reserve를 정렬한다.
3.  이 벡터에 동시에 나온 사람은 남은 체육복이 자기가 입을 것밖에 없어, 빌려줄 수가 없으므로
    answer에 더해주면서도, lost, reserve 벡터에서 각각 지워준다.
4.  이중 for문을 통해서 잃어버린 사람이 그 사람의 다음번호나 이전번호에서 옷을 빌릴 수 있는 지 한다.
5.  이 때, checked배열은 0일 때, 해당 인덱스의 번호를 가진 사람이 여분의 체육복을 빌려줄 수 있는 지를
    나타내며, 누군가에게 빌려줄 시에는 1로 바뀌게 된다.

*/

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

