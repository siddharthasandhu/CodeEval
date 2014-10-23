#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>


using namespace std;
int findModulo(int number, int devisor){
	int temp = number;
	while (temp > devisor){
		temp = temp - devisor;
	}
	return temp;
}

int main(int argv,char **argc){
	ifstream file(argc[1]);
	string line;
	int a = 0, b = 0;
	while (getline(ifp, line)){
		stringstream ss(line);
		int i;
		while (ss >> i){
			if (ss.peek() == ','){
				ss.ignore();
			}
			else {
				if (count = 0){

				}
			}
		}
		
	}
	return 0;
}