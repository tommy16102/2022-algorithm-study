#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct ball{
	int id;
	int color;
	int size;
	ball(int Id, int Color, int Size) : id(Id), color(Color), size(Size) {}
};
bool cmp(const ball& a, const ball& b){
	if(a.size == b.size){
		return a.color < b.color;
	}
	return a.size < b.size;
}
vector<ball> balls;
int c[202020];
int s[202020];
int ans[202020];
int n;
void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int ci, si;
		cin >> ci >> si;
		balls.push_back(ball(i, ci, si));
	}	
}
void solve(){
	sort(balls.begin(), balls.end(), cmp);
	int sum = 0;
	// 현재까지의 공 크기 합 - 이전까지 같은 색의 공 크기 합 - 이전까지 같은 크기의 공 크기 합 + 자신의 크기 
	for(int i=0;i<n;i++){
		c[balls[i].color] += balls[i].size;
		s[balls[i].size] += balls[i].size;
		sum += balls[i].size; 
		if(i!=0 && (balls[i-1].color == balls[i].color) && (balls[i-1].size == balls[i].size))
			ans[balls[i].id] = ans[balls[i-1].id];
		else
			ans[balls[i].id] = sum - c[balls[i].color] - s[balls[i].size] + balls[i].size;
		
	}
	for(int i=0;i<n;i++){
		cout << ans[i] << '\n';
	}
}
int main(){
	input();
	solve();
	return 0;
}
