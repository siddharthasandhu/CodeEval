#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

void printBinary(int number){
	int count = 0;
	double pow1 = 31;
	double temp = number;
	
	for (double i = pow1; i >= 0 ; --i){
		if (number == 0){
			cout << "0";
			break;
		}
		double n = 2;
		double num = pow(n, i);
		if (temp - num >= 0){
			cout << "1";
			temp = temp - num;
			count = 1;
		}
		else {
			if (count == 1){
				cout << "0";
			}
		}
	}
	cout << endl;
}

int main(int argv, char **argc){
	ifstream ifile(argc[1]);
	string line;
	while (getline(ifile, line)){
		int i;
		stringstream ss(line);
		while (ss >> i){
			printBinary(i);
		}
	}
	return 0;
}