#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    deque<string> cache;
    int answer = 0;
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities[i].size();j++){
            cities[i][j] = toupper(cities[i][j]);
        }
    }
    
    int size = 0;
    
    while(size < cities.size()){
        if(cache.size() != cacheSize){
            if(find(cache.begin(), cache.end(), cities[size]) == cache.end()){
                cache.push_back(cities[size]);
                answer += 5;
            }
            else{
                answer += 1;
                for(int i=0;i<cache.size();i++){
                    if(cache[i] == cities[size]){
                        for(int j=i;j<cache.size() - 1;j++){
                            string temp = cache[j];
                            cache[j] = cache[j+1];
                            cache[j+1] = temp;
                        }
                        break;
                    }                
                }
            }            
        }        
        else if(find(cache.begin(), cache.end(), cities[size]) == cache.end()){
            cache.push_back(cities[size]);
            cache.pop_front();
            answer += 5;
        }
        else{
            answer += 1;
            for(int i=0;i<cache.size();i++){
                if(cache[i] == cities[size]){
                    for(int j=i;j<cache.size() - 1;j++){
                        string temp = cache[j];
                        cache[j] = cache[j+1];
                        cache[j+1] = temp;
                    }
                    break;
                }
            }
        }
        size++;
    }
    
    return answer;
}
