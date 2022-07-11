#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// map을 이용하여 {str1 내 두 글자씩 끊은거, 개수} 저장 후, str2 순회하면서 map에 존재하는 거 찾으면 해당 value 빼기

int solution(string str1, string str2) {
    
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') str1[i] -= 32;
    }
    
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] >= 'a' && str1[i] <= 'z') str2[i] -= 32;
    }
    
    int sum = 0;
    int common = 0;
    map<string, int> m;
    
    for (int i = 0; i < str1.length() - 1; i++) {
        if (str1[i] < 'A' || str1[i] > 'Z' || str1[i + 1] < 'A' || str1[i + 1] > 'Z') continue;
        string str = (str1.substr(i, 2));
        m[str]++;
        sum++;
    }
    
    for (int i = 0; i < str2.length() - 1; i++) {
        if (str2[i] < 'A' || str2[i] > 'Z' || str2[i + 1] < 'A' || str2[i + 1] > 'Z') continue;
        string str = (str2.substr(i, 2));
        if (m[str] > 0) {
            common++;
            m[str]--;
        }
        sum++;
    }
    
    double calc = (common == 0 && sum == 0) ? 1 : (common == 0 || sum == 0 ) ? 0 : (double)common / (sum - common);
    
    return calc * 65536;
}
