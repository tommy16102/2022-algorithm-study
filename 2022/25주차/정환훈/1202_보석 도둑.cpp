#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
typedef long long ll;
vector<pair<int, int>> jewels;
vector<int> bags;
void input(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int m, v;
		cin >> m >> v;
		jewels.push_back({m, v});
	}
	for(int i=0;i<k;i++){
		int bag;
		cin >> bag;
		bags.push_back(bag);
	}
}
void solve(){
	sort(bags.begin(), bags.end());
	sort(jewels.begin(), jewels.end());
	priority_queue<int> pq;
	ll ans = 0;
	int id = 0;
	for(int i=0;i<bags.size();i++){
		while(id < n && bags[i] >= jewels[id].first){
			pq.push(jewels[id].second);
			id++;
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}
int main(){
	input();
	solve();
}
