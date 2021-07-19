#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.07.12 서혜민

1. times를 sort를 통해 오름차순으로 정렬!
2. 걸리는 소요 시간 = 가장 최소(min)->1, 최대(max)->(한 명이 심사받을 때 걸리는 최대 시간)*사람수
3. 이분 탐색을 통해, 해당 시간(mid)을 각각의 심사관의 소요시간으로 나눠줬을 때, 
   나눠진 값의 합은 심사를 받는 인원이 된다.
   이때, 이 인원이 매개변수로 받은 심사를 받을 인원보다 작다면, 시간을 늘려야하므로 min = mid+1
   그렇지 않다면, 시간을 줄여야하므로 max=mid-1이 되어 탐색을 재개

*/

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());
    long long min = 1;
    long long max = (long long)times[times.size() - 1]*n;
    long long mid;
    long long count;
    while (min <= max) {
        mid = (min + max) / 2;
        count = 0;
        for (int i = 0;i < times.size();i++) count += mid / times[i];
        if (count < n) {
            min = mid + 1;
        }
        else max = mid - 1;
    }
    return min;
}

int main() {
    cout << solution(6, { 7,10 });
}