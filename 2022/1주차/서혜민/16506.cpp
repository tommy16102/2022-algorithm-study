#include <iostream>
#include <string>
using namespace std;

/**

2021.12.28 서혜민

opcode와 16bit 배열을 미리 선언한 뒤, 입력받은 opcode와 rd, ra, rb를 조건에 맞춰서
배열에 있는 bit값들을 출력하도록 하였다.

**/
string opArr[12] = { "ADD", "SUB", "MOV", "AND", "OR", "NOT", "MULT", "LSFTL", "LSFTR", "ASFTR", "RL", "RR" };
string binArr[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

int findPos(string op) {
	for (int i = 0;i < 12;i++) {
		if (op.find(opArr[i]) != -1 ) return i;
	}
}

int main() {
	int N;
	cin >> N;

	string opcode;
	int rd, ra, rb;

	while (N--) {
		cin >> opcode >> rd >> ra >> rb;
		if (opcode.find("MOV") != -1 || opcode == "NOT") ra = 0;
		if (opcode[opcode.length() - 1] == 'C') {
			cout << binArr[findPos(opcode)] + "10" + binArr[rd].substr(1,3) + binArr[ra].substr(1, 3) + binArr[rb] << '\n';
		}
		else {
			cout << binArr[findPos(opcode)] + "00" + binArr[rd].substr(1, 3) + binArr[ra].substr(1, 3) + binArr[rb].substr(1, 3) + "0" << '\n';
		}
	}
}