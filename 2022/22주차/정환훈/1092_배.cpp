#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; int m;
vector<int> limit;
vector<int> weight;
void input(){
	cin >> n;
	limit = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> limit[i];
	}
	cin >> m;
	weight= vector<int>(m, 0);
	for(int i=0;i<m;i++){
		cin >> weight[i];
	}
}
void solve(){
	sort(limit.begin(), limit.end());
	reverse(limit.begin(), limit.end());
	sort(weight.begin(), weight.end());
	reverse(weight.begin(), weight.end());
	if(weight.front() > limit.front()){
		cout << -1;
		return;
	}
	int time = 0;
	while(!weight.empty()){
		int id = 0;
		time++;
		for(int i=0;i<limit.size();i++){
			for(int j=0;j<weight.size();j++){
				if(limit[i] >= weight[j]){
					weight.erase(weight.begin() + j);
					break;
				}
			}
		}
	}
	cout << time;
}

int main(){
	input();
	solve();
	return 0;	
}
