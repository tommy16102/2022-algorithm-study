#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> m;

long long find(long long num) {
    
    if (!m[num]) return num;
    
    return m[num] = find(m[num]);  
    
}

vector<long long> solution(long long k, vector<long long> room_number) {
    
    vector<long long> answer;
    
    for (int i = 0; i < room_number.size(); i++) {
        long long num = find(room_number[i]);
        answer.push_back(num);
        m[num] = num + 1;
    }
    
    return answer;
    
}
