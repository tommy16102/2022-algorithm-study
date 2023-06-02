#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string str;
vector<string> v;
void input(){
	cin >> str;
}
void solve(){
	string maxStr = "";
	string minStr = "";
	int i = 0;
	while(i < str.size()){	
		if(str[i] == 'M'){			
			int prev = i;
			i++;			
			if(i == str.size()) {
				maxStr += "1";
				break;
			}
			maxStr += "1";
			while(i < str.size() && str[i] == 'M'){
				i++;
				maxStr += "0";
			}
			// MM....M
			if(i == str.size()){
				for(int j=prev;j<maxStr.size();j++){
					maxStr[j] = '1';
				}
				break;
			}
			// MM....K.....
			if(str[i] == 'K'){
				maxStr[prev] = '5';
				maxStr += "0";
			}
			i++;
		}
		else if(str[i] == 'K'){
			maxStr += "5";
			i++;
		}		
		if(str.size() == i) break;
	}	
	i = 0;
	while(true){
		if(str[i] == 'M'){
			minStr += "1";
			i++;
			if(i == str.size()) break;
			if(str[i] == 'K'){				
				continue;
			}
			string add = "";
			while(i < str.size() && str[i] == 'M'){
				i++;
				add += "0";
			}
			minStr += add;
		}
		else if(str[i] == 'K'){
			minStr += "5";
			i++;
		}		
		if(str.size() == i) break;
	}
	cout << maxStr << '\n' << minStr;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();	
	return 0;
}	
