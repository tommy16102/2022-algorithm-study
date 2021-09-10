#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*

2021.09.11 
장르와 합만 저장하는 sumMap, 장르와 해당 음악의 인덱스와 그 음악의 재생횟수를 저장하는 map.
재생횟수가 많은 순으로 sumMap을 정렬한 뒤, 앞에서부터 해당 장르를 map을 통해서 인덱스와 재생횟수를 저장하는 벡터에서
정렬을 통해 재생횟수 내림차순, 재생횟수 같으면 인덱스 오름차순으로 정렬을 하여, 한 장르당 최대 2곡이
벡터에 들어가도록 한다.

*/

bool cmp(pair<string,int> a, pair<string,int> b) {
	return a.second > b.second;
}

bool cmp2(pair<int,int> a, pair<int,int> b){
    if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> sumMap;
    map<string,vector<pair<int,int>>> map;
    
    for(int i=0;i<genres.size();i++){
        if(sumMap.find(genres[i])==sumMap.end()){
            sumMap.insert({genres[i],plays[i]});
        }
        else sumMap[genres[i]]+=plays[i];
        
        if(map.find(genres[i])==map.end()){
            vector<pair<int,int>> v;
            v.push_back({plays[i],i});
            map.insert({genres[i],v});
        }
        else{
            vector<pair<int,int>> v = map[genres[i]];
            v.push_back({plays[i],i});
            map[genres[i]]=v;
        }
    }
    
    vector<pair<string,int>> vec( sumMap.begin(), sumMap.end() );
	sort(vec.begin(), vec.end(), cmp);
    
    for(auto i : vec){
        string s =  i.first;
        vector<pair<int,int>> v=map[s];
        sort(v.begin(),v.end(),cmp2);
        int count=0;
        
        for(auto j : v){
            if(count==2 ) break;
            answer.push_back(j.second);
            count++;
        }   
    }
    return answer;
}
