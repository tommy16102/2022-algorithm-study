#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decrypt(int encrypted, int size){
    
    string ret = "";
    
    while(encrypted){
        if(encrypted % 2 == 0) ret += " ";
        else ret += "#";
        encrypted /= 2;
    }
    
    while(ret.size() != size){
        ret += " ";
    }
    
    reverse(ret.begin(), ret.end());
    return ret;

}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<int> converted;
    
    for(int i=0;i<arr1.size();i++){
        converted.push_back(arr1[i] | arr2[i]);
    }
    vector<string> answer;
    
    for(int i=0;i<converted.size();i++){
        answer.push_back(decrypt(converted[i], n));
    }
        
    return answer;
}
