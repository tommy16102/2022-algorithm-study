#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

// bitset을 사용.

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        bitset<16> bit1(arr1[i]);
        bitset<16> bit2(arr2[i]);
        bitset<16> bit3 = bit1 | bit2;
        
        string bit = bit3.to_string();
        bit = bit.substr(bit.length() - n);
        
        string ans;
        
        for (int i = 0; i < bit.length(); i++) {
            if (bit[i] == '0') ans += ' ';
            else ans += '#';
        }
        
        answer.push_back(ans);
    }
    
    return answer;
}
