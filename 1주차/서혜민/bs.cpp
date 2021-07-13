#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

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