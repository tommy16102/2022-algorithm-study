#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int n;
int start[4] = {2, 3, 5, 7};
int p[5] = {1, 3, 5 ,7, 9};
void input(){
	cin >> n;
}

bool isPrime(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x % i == 0) return false;
	}
	return true;
}

void go(int depth, int num){
	if(depth == n){	
		if(isPrime(num))
			cout << num << '\n';
		return;
	}
	for(int i=0;i<5;i++){
		if(isPrime(num))
			go(depth + 1, num * 10 + p[i]);
	}
}

void solve(){
	for(int i=0;i<4;i++){
		go(1, start[i]);
	}
}
int main(){
	input();
	solve();
	return 0;
}
