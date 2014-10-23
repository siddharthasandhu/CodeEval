#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>



using namespace std;

int reverseNumber(int a){
	int reverse = 0;
	int number = a;
	while (number != 0){
		reverse = reverse * 10;
		reverse = reverse + number % 10;
		number = number / 10;
	}
	return reverse;
}

bool checkPalindrome(int a){
	stack<char> palin;
	string s = to_string(a);
	char const* num = s.c_str();
	char const* sec = s.c_str();
	while (isdigit(*num)){
		palin.push(*num);
		num++;
	}
	while (isdigit(*sec)){
		if (*sec == palin.top()){
			palin.pop();
			sec++;
		}
		else {
			return false;
		}
	}
	if (palin.empty()){
		return true;
	}
	else {
		return false;
	}
	return false;
}


int addProcess(int a){
	int count = 1;
	int number = a;
	int reverse = reverseNumber(a);
	int newNumber = number + reverse;
	while (!checkPalindrome(newNumber)){
		reverse = reverseNumber(newNumber);
		newNumber = newNumber + reverse;
		count++;
	}
	cout << count;
	return newNumber;
}

int main(int argc,char **argv){
	ifstream file(argv[1]);
	int finalNumber = 0;
	string line;
	while (getline(file, line)){
		int a;
		istringstream iss(line);
		while (iss >> a){
			finalNumber = addProcess(a);
			cout << " "<<finalNumber << endl;
		}
	}
	return 0;
}