#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void){

    unordered_map<int, pair<int,int>> q;

    q.insert({100, {3 ,4}});
    q.insert({200, {3 ,2}});
    q.insert({40, {1 ,4}});
    q.insert({400, {5 ,4}});
    q.insert({50, {-3 ,4}});

    for(unordered_map<int, pair<int,int>>::iterator iter = q.begin(); iter != q.end(); iter++){
        cout << iter->first << " " << iter->second.first << " " << iter->second.second <<"\n";
    }

    for(unordered_map<int, pair<int,int>>::iterator iter = q.begin(); iter != q.end();){
        cout << iter->first << " " << iter->second.first << " " << iter->second.second <<"\n";
        iter = q.erase(iter);
        if(iter == q.end())
            break;
    }

    cout << q.size();

    return 0;
}