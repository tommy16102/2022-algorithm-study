#include <iostream>
using namespace std;

/*

2021.07.26 서혜민

n(여학생), m(남학생), k(인턴)
count(팀)

여2남1->1팀이므로 최대 만들 수 있는 팀의 개수는 m이다.
for문을 통해서 팀의 개수를 1개씩 늘려가면서,
팀을 만들때마다 여, 남 학생수를 빼준다. 이때,
0) 여학생이 없거나, 남학생이 없으면 팀을 만들수 없으므로 팀 개수는 0.
1) 남은 학생수의 합이 인턴에 참여할 학생의 수와 같아지면 그 때의 팀 개수가 정답
2) 작아지면 그 때의 팀개수가 아닌 이전의 팀 개수가 정답이 된다.
3) 1,2번 경우가 아니면서 팀을 만들 수 없는 상태이면 그 때까지 만들어진 팀 개수가 정답.

*/

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int count = 0;
	int girl = n, man = m;
	bool makeTeam = false;
	for (int i = 0;i < m;i++) {
		makeTeam = false;
		if (girl >= 2 && man >= 1) {
			girl -= 2;
			man -= 1;
			count++;
			makeTeam = true;
		}
		if ((girl + man) <= k) {
			if ((girl + man) == k) cout << count << endl;
			else cout << count - 1 << endl;
			return 0;
		}
		if (!makeTeam) {
			cout << count << endl;
			return 0;
		}
	}
	cout << count << endl;
}