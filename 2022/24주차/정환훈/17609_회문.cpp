#include <iostream>
using namespace std;
string str;
void input(){
	cin >> str;
}
void solve(){
	int left = 0; int right = str.size()-1;
	int chance = 1;
	int stuckLeft = -1; int stuckRight = -1;
	for(;left<=right;left++,right--){
		if(str[left] == str[right]){
			if(left + 1 >= right - 1){
				cout << "0\n";
				return;
			}
			continue;
		}
		else{
			stuckLeft = left;
			stuckRight = right;
			break;
		}
	}
	
	left = stuckLeft + 1; right = stuckRight;
	
	for(;left<=right;left++,right--){
		if(str[left] == str[right]){
			if(left + 1 >= right - 1){
				cout << "1\n";
				return;
			}
		}
		else{
			break;
		}
	}
	
	left = stuckLeft; right = stuckRight - 1;
	
	for(;left<=right;left++,right--){
		if(str[left] == str[right]){
			if(left + 1 >= right - 1){
				cout << "1\n";
				return;
			}
			continue;
		}
		else{
			break;
		}
	}
	
	cout << "2\n";
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
