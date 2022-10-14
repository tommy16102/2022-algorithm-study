/*******************************************************************
2457 공주님의 정원
2022/10/12 이호준
# 아이디어
1. Greedy
2. 갓환훈의 코드로 연습하자..!
*******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int,int>> flower;
using namespace std;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int sm; int sd; int em; int ed;
		cin >> sm >> sd >> em >> ed;
		flower.push_back({sm * 100 + sd, em * 100 + ed});
	}
}
void solve(){
	sort(flower.begin(), flower.end());
	int date = 301;
	// cannot make 
	if(flower.front().first > date){
		cout << 0;
		return;
	}
	int i = -1;
	int temp = 0; int ans = 0; 
	while(date <= 1130 && i < n){ 
		i++;
		int flag = 0;
		for(int j=i;j<n;j++){
			// no flower to find anymore
			if(flower[j].first > date) break;
			if(flower[j].second > temp){ // find much longer life flower
				temp = flower[j].second; flag = 1;
			}
		}
		if(flag){
			date = temp; ans++;
		}
		else{
			cout << 0;
			return;
		}
		
	}
	cout << ans;
}
int main(){
	input();
	solve();
	return 0;
}