#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n; int m; int l; 
vector<int> pos;
vector<int> diff;
void input(){
	cin >> n >> m >> l;
	pos.push_back(0);
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		pos.push_back(t);
	}
	pos.push_back(l);
}

void solve(){
	sort(pos.begin(), pos.end());
	for(int i=1;i<pos.size()-1;i++){
		diff.push_back(pos[i] - pos[i-1]);
	}
	
	int left = 1; int right = l-1;
	int mid = 0;
	while(left <= right){
		mid = (left + right) / 2;
		int newStore = 0;
		for(int i=1;i<pos.size();i++){
			int d = pos[i] - pos[i-1];
			newStore += (d / mid);
			if(d % mid == 0){
				newStore--;
			}
		}
		
		if(newStore > m){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << left;
}
int main(){
	input();
	solve();
	return 0;
}
