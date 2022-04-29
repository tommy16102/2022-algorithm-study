#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

#define MAX_MIN 23 * 60 + 59

using namespace std;

map<string, int> tMap;
map<pair<string,string>, string> ioMap;
set<string> cSet;

int getMin(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    
    return 60 * h + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
 
    for (int i = 0; i < records.size(); i++) {
        
        string time;
        string number;
        string io;
        
        string record = records[i];
        
        int now = 0;
        
        int index = record.find(' ');
        time = record.substr(now, index);
        now = index + 1;
        
        index = record.find(' ', now);
        number = record.substr(now, index - now);
        now = index + 1;
        
        io = record.substr(now);
        
        cSet.insert(number);
        
        if (io == "IN") {
            ioMap[{number, io}] = time;
            tMap[number] += (MAX_MIN - getMin(time));
        }
        else {
            ioMap[{number, io}] = time;
            string iTime = ioMap[{number, "IN"}];
            tMap[number] -= (MAX_MIN - getMin(time)); 
        }
    }
    
    int dMin = fees[0];
    int dCost = fees[1];
    int uMin = fees[2];
    int uCost = fees[3];
    vector<int> ans;
    
    for (string num : cSet) {
        int m = tMap[num];
        
        if(m < dMin) ans.push_back(dCost);
        else ans.push_back(dCost + ceil((m-dMin)/(double)uMin) * uCost);
    }
    
    return ans;
}