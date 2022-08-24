#include <bits/stdc++.h>
using namespace std;

int n;
class CMD {

public:
	string opcode;
	int rD; int rA; int rB;
	CMD(string op, int rd, int ra, int rb) {
		opcode = op;
		rD = rd;
		rA = ra;
		rB = rb;
	}

	void convert() {
		//opcod 0 r D r   A if(4==0) rB, 15 = 0, elif(4==1) #c
		//01234 5 678 91011 12131415
		string op; string rd; string ra; string last;
		switch (rD) {
		case 0:
			rd = "000";
			break;
		case 1:
			rd = "001";
			break;
		case 2:
			rd = "010";
			break;
		case 3:
			rd = "011";
			break;
		case 4:
			rd = "100";
			break;
		case 5:
			rd = "101";
			break;
		case 6:
			rd = "110";
			break;
		case 7:
			rd = "111";
			break;
		}
		switch (rA) {
		case 0:
			ra = "000";
			break;
		case 1:
			ra = "001";
			break;
		case 2:
			ra = "010";
			break;
		case 3:
			ra = "011";
			break;
		case 4:
			ra = "100";
			break;
		case 5:
			ra = "101";
			break;
		case 6:
			ra = "110";
			break;
		case 7:
			ra = "111";
			break;
		}

		if (opcode == "ADD") op = "00000";
		if (opcode == "ADDC") op = "00001";
		if (opcode == "SUB") op = "00010";
		if (opcode == "SUBC") op = "00011";
		if (opcode == "MOV") op = "00100";
		if (opcode == "MOVC") op = "00101";
		if (opcode == "AND") op = "00110";
		if (opcode == "ANDC") op = "00111";
		if (opcode == "OR") op = "01000";
		if (opcode == "ORC") op = "01001";
		if (opcode == "NOT") op = "01010";
		if (opcode == "MULT") op = "01100";
		if (opcode == "MULTC") op = "01101";
		if (opcode == "LSFTL") op = "01110";
		if (opcode == "LSFTLC") op = "01111";
		if (opcode == "LSFTR") op = "10000";
		if (opcode == "LSFTRC") op = "10001";
		if (opcode == "ASFTR") op = "10010";
		if (opcode == "ASFTRC") op = "10011";
		if (opcode == "RL") op = "10100";
		if (opcode == "RLC") op = "10101";
		if (opcode == "RR") op = "10110";
		if (opcode == "RRC") op = "10111";

		if (op[4] == '0') {
			// rb 경우
			switch(rB) {
			case 0:
				last = "000";
				break;
			case 1:
				last = "001";
				break;
			case 2:
				last = "010";
				break;
			case 3:
				last = "011";
				break;
			case 4:
				last = "100";
				break;
			case 5:
				last = "101";
				break;
			case 6:
				last = "110";
				break;
			case 7:
				last = "111";
				break;
			}
		}
		else if (op[4] == '1') {
			switch (rB) {
			case 0:
				last = "0000";
				break;
			case 1:
				last = "0001";
				break;
			case 2:
				last = "0010";
				break;
			case 3:
				last = "0011";
				break;
			case 4:
				last = "0100";
				break;
			case 5:
				last = "0101";
				break;
			case 6:
				last = "0110";
				break;
			case 7:
				last = "0111";
				break;
			case 8:
				last = "1000";
				break;
			case 9:
				last = "1001";
				break;
			case 10:
				last = "1010";
				break;
			case 11:
				last = "1011";
				break;
			case 12:
				last = "1100";
				break;
			case 13:
				last = "1101";
				break;
			case 14:
				last = "1110";
				break;
			case 15:
				last = "1111";
				break;
			default:
				last = "default!!!";
			}
		}
		cout << op << "0" << rd << ra;

		if (op[4] == '0') {
			cout << last << "0";
		}
		else if (op[4] == '1') {
			cout << last;
		}

		cout << "\n";

	}

};
vector<CMD> cmds;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string opcode;
		int rD; int rA; int rB;
		cin >> opcode >> rD >> rA >> rB;
		cmds.push_back(CMD(opcode, rD, rA, rB));
	}
}

void solve() {
	for (int i = 0; i < cmds.size(); i++) {
		cmds[i].convert();
	}
}

int main(void) {

	input();
	solve();
}