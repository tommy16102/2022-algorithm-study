#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> cnt;
int n;
void input(){
	cin >> n;
	cnt = vector<int>(n, 0);
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}
void solve(){
	if(n <= 1){
		cout << 0;
		return;
	}
	
	for(int i=0;i<n;i++){
		double maxD = -10000000000;
		for(int j=i+1;j<n;j++){
			int dx = j - i;
			int dy = v[j] - v[i];
			double d = (double)dy / (double) dx;
			if(d > maxD){
				maxD = d;	
				cnt[i]++;
				cnt[j]++;
			}			
				
		}
	}
	
	sort(cnt.begin(), cnt.end());
	cout << cnt.back();
	
}
int main(){
	input();
	solve();
	return 0;
}
