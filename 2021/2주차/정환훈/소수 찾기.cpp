#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    푼 사람 : 구글    푼 날짜 : 2021/07/19
    
    기본 아이디어 : next_permutation을 사용해 모든 경우 구한다

*/

bool is_prime(int num) {

    if (num < 2)
        return false;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return false;
    }

    return true;

}

int solution(string numbers) {
    int answer = 0;


    vector<int> nums;

    for (int i = 0; i < numbers.size(); i++) {
        nums.push_back(numbers[i] - '0');
    }

    sort(nums.begin(), nums.end());


    vector<int> permutation;

    do {
        for (int i = 0; i <= nums.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + nums[j];
                permutation.push_back(tmp);
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    sort(permutation.begin(), permutation.end());
    permutation.erase(unique(permutation.begin(), permutation.end()), permutation.end());

    for (int i = 0; i < permutation.size(); i++) {
        if (is_prime(permutation[i])) 
            answer++;
    }

    return answer;
}