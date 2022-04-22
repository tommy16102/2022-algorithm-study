#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {

    set<string> orgSet;
    for (string gem : gems) orgSet.insert(gem);

    set<string> gemSet;
    map<string, int> map;

    int L = 0, R = 0;

    map[gems[L]]++;
    gemSet.insert(gems[L]);

    int pointL = 100001;
    int pointR = pointL + 100001;
    int len = gems.size();

    while (1) {
        
        if (orgSet.size() == gemSet.size()) {
            int orgLen = pointR - pointL;
            int nLen = R - L;
            if ((orgLen > nLen) || ((orgLen == nLen) && (L < pointL))) {
                pointR = R;
                pointL = L;
            }
        }
        
        if (gemSet.size() < orgSet.size()) {
            R++;
            if (R >= len) break;
            map[gems[R]]++;
            gemSet.insert(gems[R]);
        }
        else {
            map[gems[L]]--;
            if (!map[gems[L]]) gemSet.erase(gems[L]);
            L++;
            if (L >= len) break;
            if (L > R) {
                R = L;
                map.clear();
                gemSet.clear();
                map[gems[L]]++;
                gemSet.insert(gems[L]);
            }
        }  
        
    }

    vector<int> ans;
    ans.push_back(pointL + 1);
    ans.push_back(pointR + 1);
    
    return ans;
    
}
