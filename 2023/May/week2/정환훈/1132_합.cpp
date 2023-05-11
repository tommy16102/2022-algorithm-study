#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
int n;
vector<string> v; 
map<char, ll> m;
bool nozero[10];
void input(){
	cin >> n;
	v = vector<string>(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
}
bool cmp(pair<char,ll> p1, pair<char,ll> p2){
	return p1.second > p2.second;
}
void solve(){
	// ABCDEFGHIJ
	for(int i=0;i<v.size();i++){
		nozero[v[i][0] - 'A'] = true;
		for(int j=0;j<v[i].size();j++){
			m[v[i][j]] += pow(10, v[i].size() - 1 - j);
		}
	}
	vector<pair<char,ll>> vv;
	for(auto e : m){
		vv.push_back({e.first, e.second});
	}
	sort(vv.begin(), vv.end(), cmp);
	map<char, ll> digit;
	int id = 9; char zero = '?';
	for(auto e : vv){
		digit[e.first] = id--;		
		if(id == -1) zero = e.first;
	}
	if(zero != '?' && nozero[zero - 'A']){
		int swapNum = 1; char swapChar = '!';
		bool bye = true;
		while(bye){			
			for(int i=0;i<10;i++){
				if(swapNum == digit[i + 'A']){
					if(nozero[i]){
						swapNum++; break;
					}
					else{
						//cout << zero <<  " swap with : " << char(i+'A') << '\n';
						swapChar = i+'A';
						// B < ? < J --
						// B = 1; J = 0;
						
						vector<char> vvv;
						for(int i=1;i<digit[swapChar] - digit[zero];i++){
							for(int j=0;j<10;j++){
								if(digit['A'+j] == i){									
									vvv.push_back('A'+j);
									break;									
								}
							}
						}
						for(char c : vvv) digit[c]++;		 
						digit[zero] = 0;
						digit[swapChar] = 1;
						bye = false;
					}
				}
			}
		}
		swap(digit[swapChar], digit[zero]);
	}
	
	vector<ll> l;
	
	for(int i=0;i<v.size();i++){
		string temp = "";
		for(int j=0;j<v[i].size();j++){
			char c = '0';
			temp += c + digit[v[i][j]];
		}		
		l.push_back(stoll(temp));
	}
	ll ans = 0;
	for(auto e : l){
		ans += e;
	}
	cout << ans;
	
}

int main(){
	
	input();
	solve();
	return 0;
}
