#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s1, s2;
void input(){
	cin >> s1 >> s2;
}
int romanToInt(string s){
	int ret = 0;
	for(int i=0;i<s.size();i++){		
		if(s[i] == 'I'){
			// IV, IX
			if(i != s.size()-1 && s[i+1] == 'V'){
				i++;
				ret += 4;
			}
			else if(i != s.size()-1 && s[i+1] == 'X'){
				i++;
				ret += 9;
			}
			else{
				ret += 1;
			}
		}
		else if(s[i] == 'V'){
			ret += 5;
		}
		else if(s[i] == 'X'){
			// XL, XC
			if(i != s.size()-1 && s[i+1] == 'L'){
				i++;
				ret += 40;
			}
			else if(i != s.size()-1 && s[i+1] == 'C'){
				i++;
				ret += 90;
			}
			else{
				ret += 10;
			}			
		}
		else if(s[i] == 'L'){
			ret += 50;
		}
		else if(s[i] == 'C'){
			// CD, CM
			if(i != s.size()-1 && s[i+1] == 'D'){
				ret += 400;
				i++;
			}
			else if(i != s.size()-1 && s[i+1] == 'M'){
				ret += 900;				
				i++;
			}
			else{
				ret += 100;
			}			

		}
		else if(s[i] == 'D'){
			ret += 500;
		}
		else if(s[i] == 'M'){			
			ret += 1000;
		}
	}
	return ret;
}
string intToRoman(int i){
	string ret = "";
	while(i > 0){
		if(i>=1000){
			i -= 1000;
			ret += "M";
		}
		else if(i>= 900 && i < 1000){
			i -= 900;
			ret += "CM";
		}
		else if(i>=500 && i<900){
			i -= 500;
			ret += "D";
		}
		else if(i>=400 && i<500){
			i -= 400;
			ret += "CD";
		}
		else if(i>=100 && i<400){
			i -= 100;
			ret += "C";
		}
		else if(i>=90 && i<100){
			i -= 90;
			ret += "XC";
		}
		else if(i>=50 && i<90){
			i -= 50;
			ret += "L";
		}
		else if(i>=40 && i<50){
			i -= 40;
			ret += "XL";
		}
		else if(i>=10 && i<40){
			i -= 10;
			ret += "X";
		}
		else if(i>=9 && i<10){
			i -= 9;
			ret += "IX";
		}
		else if(i>=5 && i<9){
			i -=5;
			ret += "V";
		}
		else if(i>=4 && i<5){
			i -=4;
			ret += "IV";
		}
		else if(i>=1 && i<4){
			i -= 1;
			ret += "I";
		}
	}
	return ret;
}
void solve(){
	int i1 = romanToInt(s1);
	int i2 = romanToInt(s2);
	int sum = i1+i2;
	cout << sum << '\n' << intToRoman(i1+i2);	
}
int main(){
	
	input();
	solve();
	return 0;
}
