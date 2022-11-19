#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
typedef long long ll;
vector<int> primes;
bool isPrime[4000001];
int dp[4000001];
ll sum[400001];
void input(){
	cin >> n;
}
void solve(){	
	for(int i=2;i<=n;i++){
		isPrime[i] = true;
	}
	
	for(int i=2;i<=sqrt(n);i++){
		if(!isPrime[i]){
			continue;
		}
		for(int j=i+i;j<=n;j+=i){ 
			isPrime[j] = false;
		}
	}	
	for(int i=2;i<=n;i++){
		if(isPrime[i])
			primes.push_back(i);
	}
	int start = 0; int end = 0;
	int ans = 0;
	int S = 0;	
	while(true){
		if(S >= n){
			S -= primes[start++];
		}
		else if(end == primes.size()){
			break;
		}
		else{
			S += primes[end++];
		}
		if(S == n){
			ans++;
		}
	}
	cout << ans;
	
}
int main(){
	input();
	solve();
	return 0;
}
