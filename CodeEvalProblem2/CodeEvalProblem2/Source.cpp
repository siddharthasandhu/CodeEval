#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <stack>
using namespace std;


bool checkPalindrome(int a){
	stack<char> pal;
	int count = 0;
	int number = a;
	string s;
	ostringstream convert;
	convert << a;
	s = convert.str();
	for (char& c : s){
		pal.push(c);
	}
	while (count < 3){
		for (char& c : s){
			if (pal.top() == c){
				pal.pop();
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

bool checkPrime(int a){
	int b = sqrt(a);
	for (int i = 2; i <= b; i++){
		if (a%i == 0){
			return 0;
		}
	}

	return 1;
}
int main(){
	bool answer;
	for (int i = 1000; i > 0; i--){
		answer = checkPalindrome(i);
		if (answer){
			answer = checkPrime(i);
			if (answer){
				cout << i;
				break;
			}
		}
	}
	return 0;
}