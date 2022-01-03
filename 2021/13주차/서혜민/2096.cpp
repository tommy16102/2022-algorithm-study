#include <iostream>
#include <algorithm>
using namespace std;

/*

최초로 3개의 수를 입력받을 때는 ,min과 max모두 해당 수로 해주고,
그 이후부터는 이전의 min과 max를 통해 계산을 하여 작은 수는 min에, 큰 수는 max에 저장을 해주며 진행한다.

*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int _minA, _minB, _minC;
	int _maxA, _maxB, _maxC;
	int minA,minB, minC;
	int maxA, maxB, maxC;
	int a, b, c;
	for (int i = 0;i < N;i++) {

		cin >> a >> b >> c;
		if (i == 0) {
			_minA = _maxA = a;
			_minB = _maxB = b;
			_minC = _maxC = c;
			maxA = _maxA; maxB = _maxB; maxC = _maxC;
			minC = _minC; minB = _minB; minA = _minA;
			
		}
		else {
			minA = a + min(_minA, _minB);
			minB = b + min(_minA, min(_minB,_minC));
			minC = c + min(_minB, _minC);
			maxA = a + max(_maxA, _maxB);
			maxB = b + max(_maxA, max(_maxB, _maxC));
			maxC = c + max(_maxB, _maxC);
			_minA = minA; _minB = minB; _minC = minC;
			_maxA = maxA; _maxB = maxB; _maxC = maxC;
		}
		
	}
	cout << max(maxA, max(maxB, maxC)) << ' ' << min(minA, min(minB, minC)) << endl;
}
