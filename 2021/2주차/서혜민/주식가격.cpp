#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.19 서혜민

시간 순서대로 정렬이 된 이 벡터 내에서
이중 포문을 통해 벡터 내의 각각의 원소를 기준으로
그 원소보다 이상인 원소이면 1초씩 증가시키고,
그렇지 않고 작은게 나온다면 1초를 증가시킨 뒤, 반복문은 다음 원소로 넘어가게된다.

*/

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int second;
	for (int i = 0;i < prices.size();i++) {
		second = 0;
		for (int j = i + 1;j < prices.size();j++) {
			if (prices[i] <= prices[j]) second++;
			else {
				second++;
				break;
			}
		}
		answer.push_back(second);
	}
	return answer;
}
