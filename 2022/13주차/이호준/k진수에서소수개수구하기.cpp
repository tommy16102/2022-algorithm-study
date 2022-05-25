#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

bool prime(ll n) { // 소수 판별
    if(n < 2) return false;
        
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    
    return true;
}

string convert_num(int n, int k) { // k진수로 변환
    string ret = "";
    
    while(n) {
        ret += to_string(n % k);
        n /= k;
    }
    
    return string(ret.rbegin(), ret.rend());
}

int get_answer(string num) { // 0을 기준으로 parsing하여 소수이면 count
    string tmp = "";
    int ret = 0;
    
    for(int i=0; i<num.length(); ++i) {
        if(num[i] == '0' && !tmp.empty()) {
            ll n = stoll(tmp);
            if(prime(n)) ret++;
            tmp = "";
        }
        else tmp += num[i];
    }
    
    if(!tmp.empty()) {
        ll n = stoll(tmp);
        if(prime(n)) ret++;
    }
    
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num = convert_num(n, k);
    
    return get_answer(num);
}