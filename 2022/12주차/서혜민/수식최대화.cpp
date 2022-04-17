#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(string ex, string ops) {
    for (int i = 0; i < 3; i++) {

        char op = ops[i];
        for (int j = 0; j < ex.length(); j++) {
            if (ex[j] == op) {
                int L = j, R = j;
                L--; R++;
                if (!(ex[R] >= '0' && ex[R] <= '9')) R++;
                while (L >= 0 && ex[L] >= '0' && ex[L] <= '9') L--;
                while (R < ex.length() && ex[R] >= '0' && ex[R] <= '9') R++;
                L++; R--;
                if (L == 1 || (L>=2 && !( ex[L-2] >= '0' && ex[L-2] <= '9'))) L--;
                long long numL = stoll(ex.substr(L, R - L));
                long long numR = stoll(ex.substr(j + 1, R - j));

                long long res;
                if (ex[j] == '+') res = numL + numR;
                else if (ex[j] == '*') res = numL * numR;
                else res = numL - numR;

                string resS = to_string(res);
                ex.replace(L, R - L + 1, resS);
                j = L + resS.length() - 1;

            }
        }
    }
    return abs(stoll(ex));
}

long long solution(string ex) {

    long long ans = 0;

    ans = max(ans, calc(ex, "*+-"));
    ans = max(ans, calc(ex, "*-+"));
    ans = max(ans, calc(ex, "+-*"));
    ans = max(ans, calc(ex, "+*-"));
    ans = max(ans, calc(ex, "-+*"));
    ans = max(ans, calc(ex, "-*+"));

    return ans;
}
