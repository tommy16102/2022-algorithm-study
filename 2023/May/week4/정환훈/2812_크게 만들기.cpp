#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n, k;
stack<int> st;
vector<int> v;
string str;
void input(){
	cin >> n >> k;
	v = vector<int>(n);
	cin >> str;
	for(int i=0;i<str.size();i++){
		char c = str[i];
		v[i] = c - '0';		
	}
}
void solve(){
	for(int i=0;i<n;i++){
		if(st.empty()){
			st.push(v[i]);
		}
		else{
			while(!st.empty() && k>0 && st.top() < v[i]){
				k--;
				st.pop();				
			}
			st.push(v[i]);
		}
	}
	while(k > 0){
		k--;
		st.pop();
	}
	string ans;
	while(!st.empty()){
		int e = st.top();
		st.pop();		
		ans += e + '0';
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}
