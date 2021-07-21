#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.21 서혜민

얼굴 종류의 옷이 a개, 상의 종류의 옷이 b개가 있다면
스파이가 고를 수 있는 전체 조합은 이 둘을 모두 안입는 것부터
얼굴 종류의 옷만 입거나, 상의 종류의 옷만 입거나 이 두 종류의 옷을 모두 입는 것 까지 존재한다.
이 경우를 모두 계산하면 (a+1)*(b+1)이 된다.
하지만 스파이는 최소 한 개의 옷은 입어야하므로 모두 입지 않는 경우인 하나를 빼면
정답은 (a+1)(b+1)-1이 된다.

옷의 종류의 개수를 구할 때는 이미 존재하는 옷이면 해당 인덱스를 찾아서 개수를 하나 더해주고,
존재하지 않다면 벡터에 새롭게 삽입을 해준다.
이후 벡터 내에서 종류의 개수에 1(입지 않는 경우)을 더한 값을 곱한 뒤,
최종적으로 모두 입지 않는 경우인 하나를 뺀 값이 정답이 된다.

*/

vector<pair<string, int>> matches;
int kindExist(string kind) {
	for (int i = 0;i < matches.size();i++) {
		if (kind == matches[i].first) return i;
	}
	return -1;
}

int solution(vector<vector<string>> clothes) {
	int index = 0;
	for (int i = 0;i < clothes.size();i++) {
		if ((index = kindExist(clothes[i][1])) != -1) {
			matches[index].second++;
		}
		else matches.push_back(make_pair(clothes[i][1], 1));
	}
	int answer = 1;
	for (int i = 0;i < matches.size();i++) {
		answer *= (matches[i].second + 1);
	}
	return answer - 1;
}

int main() {
	vector<vector<string>> v = { {"yellow","headgear"},{"blue","eyewear"},{"green","headgear"} };
	solution(v);
}