#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> pre;
vector<int> in;
vector<int> post;
void input(){
	cin >> n;
	pre = vector<int>(n);
	in = vector<int>(n);
	// me left right
	for(int i=0;i<n;i++){
		cin >> pre[i];
	}
	// left me right
	for(int i=0;i<n;i++){
		cin >> in[i];
	}
}
void go(int left, int right, int root){	
	for(int i=left;i<=right;i++){
		if(pre[root] == in[i]){
			go(left, i-1, root+1);
			go(i+1, right, root+i+1-left);
			cout << pre[root] << " " ;
		}
	}
}
void solve(){
	post = vector<int>(n);
	go(0, n-1, 0);
	cout << '\n';
}
int main(){	 
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}	
