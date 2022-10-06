#include <iostream>
#include <string> 
#include <vector>
using namespace std;
int t;
int n;
long long dpS[101];

void init(){
	int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
	for(int i=1;i<=9;i++){
		dpS[i] = num[i];
	}
	dpS[6] = 6;
	// 27 36 45
	for(int i=9;i<=100;i++){
		dpS[i] = 888888888888888;
		for(int j=2;j<8;j++){
			dpS[i] = min(dpS[i], num[j] + dpS[i-j] * 10);
		}
	}
}
void input(){
	cin >> n;
}
void solve(){
	cout << dpS[n] << " ";	
	while(n){
		if(n%2 != 0){
			cout << 7;
			n -= 3;
		}
		else{
			cout << 1;
			n -=2;
		}
	}
	cout << '\n';
}
int main(){
	cin >> t;
	init();
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
