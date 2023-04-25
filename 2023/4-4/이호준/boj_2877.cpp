/*******************************************************************
Algorithm Study
Baekjoon 2877 4와 7
2023/04/25 이호준
# 아이디어
1. Brute Force 인줄 알았으나 수학이었다.
*******************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

#define NUM_OF_CASE 2

using namespace std;

int getNumOfDigits(int k){
    int numOfDigits = 1;

    while(k > 0){
        k -= pow(NUM_OF_CASE, numOfDigits);
        numOfDigits++;
    }

    return numOfDigits - 1;
}

int getCardinal(int k, int numOfDigits){
    int sum = 0;
    for(int i = 1; i < numOfDigits; i++){
        sum += pow(NUM_OF_CASE, i);
    }

    return k - sum;
}

string getAnswer(string base, int cardinal){

    for(int i = base.length()-1; i >= 0; i--){
        if(cardinal % 2 != 0) base[i] = '7';
        cardinal /= 2;
    }
    return base;
}

int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int k;

    cin >> k;

    int numOfDigits = getNumOfDigits(k);
    int cardinal = getCardinal(k, numOfDigits);

    cout << getAnswer(string(numOfDigits, '4'), cardinal - 1);

    return 0;
}

// 1 2   3   4  5   6    7    8   9   10    11    12   13   14 
// 4 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777
// 1 2   1   2   3   4   1   2    3    4   5   6  7   8 