#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int t, f; map<string, int> m;
vector<string> names;
int p[202020];
int r[202020];
vector<pair<string,string>> v;
int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa == pb) return;
	if(r[pa] < r[pb]) swap(pa, pb);	
	p[pb] = pa;
	r[pa] += r[pb];
}
void input(){
	cin >> f;
	v = vector<pair<string, string>>(f);
	names.clear();
	m.clear();
	for(int i=0;i<f;i++){
		cin >> v[i].first >> v[i].second;
		names.push_back(v[i].first);
		names.push_back(v[i].second);
	}	
}
void solve(){
	sort(names.begin(), names.end());
	names.erase(unique(names.begin(), names.end()), names.end());	
	int id = 0;
	for(string name : names) m[name] = id++;
	for(int i=0;i<202020;i++) {	p[i] = i; r[i] = 1; }
	
	for(auto e : v){
		string f1 = e.first; string f2 = e.second;
		int i1 = m[f1]; int i2 = m[f2];
		merge(i1, i2);
		cout << r[find(i1)] << '\n';
	}
}
int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		input();
		solve();
	}
	return 0;
}
