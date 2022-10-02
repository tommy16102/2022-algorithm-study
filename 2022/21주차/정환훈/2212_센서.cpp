#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; int k;
vector<int> pos;
void input(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		pos.push_back(t);
	}
}
void solve(){
	int answer = 0;
	sort(pos.begin(), pos.end());
	vector<int> diff(n-1);
	for(int i=1;i<pos.size();i++){
		diff[i-1] = pos[i] - pos[i-1];
	}
	sort(diff.begin(), diff.end());
	for(int i=0;i<n-k;i++){
		answer += diff[i];
	}
	cout << answer;
}

int main(){
	input();
	solve();
	return 0;
}
