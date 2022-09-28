#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; int h;
vector<int> heights;
vector<int> ups;
vector<int> downs;
vector<pair<int,int> > v;

void input(){
	cin >> n >> h;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		heights.push_back(temp);
		if(i%2 == 0)
			ups.push_back(temp);
		else
			downs.push_back(temp);
		
	}
}
void solve(){
	sort(heights.begin(), heights.end());
	sort(ups.begin(), ups.end());
	sort(downs.begin(), downs.end());	
	for(double i=0.5;i<h;i++){
		int upMeets = ups.size() -  (lower_bound(ups.begin(), ups.end(), i) - ups.begin() );
		int downMeets = downs.size() -  (lower_bound(downs.begin(), downs.end(), h - i) - downs.begin() );
		v.push_back({(upMeets + downMeets), (int)i});		
		//cout << "i : " << i << "    " << ups.size() -  (lower_bound(ups.begin(), ups.end(), i) - ups.begin() ) << endl;
		//cout << "i : " << i << "    " << downs.size() -  (lower_bound(downs.begin(), downs.end(), h - i) - downs.begin() ) << endl;
	}
	sort(v.begin(), v.end());
	int minValue = v[0].first;
	int howMany = 0;
	for(auto e : v){
		if(e.first == minValue)
			howMany++;
	}
	
	cout << minValue << " " << howMany;
}

int main(){
	input();
	solve();
	return 0;
}
