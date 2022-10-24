#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
void input(){
	cin >> n >> m;
	v = vector<int>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}

bool test(int mid){
	int sum = 0;
	int cnt = 1;
	for(int i=0;i<n;i++){
		if(v[i] > mid){
			return false;
		}
		sum += v[i];
		if(sum > mid){
			sum = v[i];
			cnt++;
		}
	}
	return m >= cnt;
}

void solve(){
	int sum = 0;
	int ans = 0;
	for(auto e : v){
		sum += e;
	}
	int left = 1;
	int right = sum;
	
	while(left <= right){
		int mid = (left + right) / 2;
		if(test(mid)){ // it meets condition
			ans = mid;
			right = mid - 1;
		}
		else{ // no... too many bd!
			left = mid + 1;
		}
	}
	cout << ans;
}

int main(){
	input();
	solve();		
	
	return 0;
}
