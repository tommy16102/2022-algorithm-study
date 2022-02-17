#include <iostream>
#include <bitset>
using namespace std;

/*

2022.2.17
bitset으로 2진수 변환 후, 1의 개수를 센다.

*/

int main() {
	int X;
	cin >> X;

	int ans = 0;
	for (char num : bitset<7>(X).to_string()) if (num == '1') ans++;

	cout << ans;
}