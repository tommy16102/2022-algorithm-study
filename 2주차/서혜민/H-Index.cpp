#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.07.19  서혜민

먼저 논문의 인용횟수가 담긴 citations를 정렬을 한다.
이후, 논문의 인용횟수를 인덱스로서 해당 논문 인용 횟수별 논문 개수를 담은 countSum배열에
정렬이 된 citations 벡터에서 가장 적은 수부터 가장 많은 수까지 0부터 계속 값을 누적으로 더해준 값을 저장한다.
결국 이를 통하여, countSum배열에는 해당 인용 횟수 이하의 논문의 개수가 저장이 된다.

문제의 특성상 인용 횟수를 의미하는 h는 0이 될 수 없으므로, countSum배열에서 인덱스 1부터 끝까지 탐색을 하면서
h번 이상 인용된 논문의 개수는 [ 전체 논문 - countSum[h-1]의 값 ] 이고
h번 이하 인용된 논문의 개수는 [ countSum[h-1]의 값] 이므로
각각 이 값들이 h보다 이상/이하이면서 가장 인덱스가 큰 값이 정답이 된다.

*/

int countSum[10001];//0~10000회의 논문 인용 횟수별 논문 개수 
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int sum = 0;
    int num = 0;
    for (int i = 0;i < citations.size();i++) {
        countSum[citations[i]] = ++sum;
    }
    int maxIndex = 0;
    for (int i = 1;i <= 10000;i++) {
        if (countSum[i] == 0) countSum[i] = countSum[i - 1];
        int sumUp = citations.size() - countSum[i - 1];//이상
        int sumDown = countSum[i - 1];//이하
        if (i > maxIndex && sumUp >= i && sumDown <= i) maxIndex = i;
    }
    return maxIndex;
}

int main() {
    cout << solution({ 3,0,6,1,5, });
}