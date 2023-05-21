#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <queue>
using namespace std;
int n, m;
map<int,int> difMap;
struct cmp1{
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
		if(p1.second == p2.second){
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
	}
};
struct cmp2{
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
		if(p1.second == p2.second){
			return p1.first > p2.first;
		}
		return p1.second > p2.second;
	}
	
};
void input(){
	cin >> n;
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq1;
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> pq2;
	for(int i=0;i<n;i++){
		int p, l;
		cin >> p >> l;		
		difMap[p] = l;
		pq1.push({p, l});
		pq2.push({p, l});
	}
	cin >> m;
	for(int i=0;i<m;i++){		
		string cmd;
		cin >> cmd;
		if(cmd == "add"){
			int p, l;
			cin >> p >> l;
			difMap[p] = l;
			pq1.push({p, l});
			pq2.push({p, l});									
		}
		else if(cmd == "recommend"){
			int x;
			cin >> x;
			// hardest & biggest			
			if(x == 1){
				while(difMap.find(pq1.top().first) == difMap.end() || difMap[pq1.top().first] != pq1.top().second){
					pq1.pop();
				}
				cout << pq1.top().first << '\n';
			}
			// easiest & smallest
			else if(x == -1){
				while(difMap.find(pq2.top().first) == difMap.end() || difMap[pq2.top().first] != pq2.top().second){
					pq2.pop();
				}
				cout << pq2.top().first << '\n';
			}
		}
		else if(cmd == "solved"){
			int p;
			cin >> p;			
			difMap.erase(p);
		}
	}
}
void solve(){	
}
int main(){	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
