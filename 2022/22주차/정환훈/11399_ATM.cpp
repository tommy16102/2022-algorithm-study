#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; vector<int> p;
void input(){
	cin >> n;
	p = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
}
void solve(){
	sort(p.begin(), p.end());
	int sum = 0;
	for(int i=0;i<p.size();i++){
		int delay = 0;
		for(int j=0;j<=i;j++){
			delay += p[j];
		}
		
		sum += delay;
	}
	cout << sum;
}
int main(){
	input();
	solve();
	return 0;
}
