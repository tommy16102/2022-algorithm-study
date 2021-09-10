#include string
#include vector
#include algorithm
#include map
using namespace std;

bool cmp(pairstring,int a, pairstring,int b) {
	return a.second  b.second;
}

bool cmp2(pairint,int a, pairint,int b){
    if (a.first == b.first) return a.second  b.second;
	return a.first  b.first;
}

vectorint solution(vectorstring genres, vectorint plays) {
    vectorint answer;
    
    mapstring, int sumMap;
    mapstring,vectorpairint,int map;
    
    for(int i=0;igenres.size();i++){
        if(sumMap.find(genres[i])==sumMap.end()){
            sumMap.insert({genres[i],plays[i]});
        }
        else sumMap[genres[i]]+=plays[i];
        
        if(map.find(genres[i])==map.end()){
            vectorpairint,int v;
            v.push_back({plays[i],i});
            map.insert({genres[i],v});
        }
        else{
            vectorpairint,int v = map[genres[i]];
            v.push_back({plays[i],i});
            map[genres[i]]=v;
        }
    }
    
    vectorpairstring,int vec( sumMap.begin(), sumMap.end() );
	sort(vec.begin(), vec.end(), cmp);
    
    for(auto i  vec){
        string s =  i.first;
        vectorpairint,int v=map[s];
        sort(v.begin(),v.end(),cmp2);
        int count=0;
        
        for(auto j  v){
            if(count==2 ) break;
            answer.push_back(j.second);
            count++;
        }   
    }
    return answer;
}