#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<int,int>> v;
int cache[101][100001];
int total;
void input(){
	cin >> n;
	total = 0;
	v = vector<pair<int,int>>(n);
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
		total += a*b;
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<100001;j++){
			cache[i][j] = -1;
		}
	}
}

int go(int depth, int sum){
	if(sum > total/2) return 0;		
	if(depth == n){
		if(sum == total/2) {			
			return 1;
		}
		return 0;
	}
	int& ret = cache[depth][sum];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i<=v[depth].second;i++){
		ret += go(depth+1, sum + i * v[depth].first);
	}
	return ret;
}
bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
	return p1.first > p2.first;
}
void solve(){
	sort(v.begin(), v.end(), cmp);
	if(total%2 == 0 && go(0, 0)){	
		cout << "1\n";
	}
	else{
		cout << "0\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<3;i++){
		input();
		solve();
	}
	return 0;
}
