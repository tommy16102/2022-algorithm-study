#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef struct info{
	int x, pos, id;
}info;
bool cmp(const info& a, const info& b){
	return a.x < b.x;
}
int n;
vector<info> v;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int o, r;
		cin >> o >> r;
		v.push_back({o-r, -1, i});
		v.push_back({o+r, 1, i});
	}
}
bool sol(){
	stack<int> st;
	for(int i=1;i<v.size();i++){
		if(v[i-1].x == v[i].x) return false;				
	}
	for(int i=0;i<v.size();i++){
		if(v[i].pos == -1){
			st.push(v[i].id);
		}
		else if(v[i].id == st.top()){
			st.pop();
		}
		else return false;
	}
	return true;
}
void solve(){
	sort(v.begin(), v.end(), cmp);
	if(sol()){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}
int main(){
	input();
	solve();	
	return 0;
}	
