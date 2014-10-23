#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;
int minCoin(int number){
	int  a = 0, b = 0 , c = 0;
	int temp;
	if (number > 4){
		a = number / 5;
		temp = number % 5;
		if (temp > 2){
			b = temp / 3;
			temp = temp % 3;
			c = temp;
		}
		else{
			c = temp;
		}
	}
	else if(number > 2) {
		b = number / 3;
		temp = number % 3;
		c = temp;
	}
	else if (number > 0){
		c = number;
	}
	return a + b + c;
}

int main(int argv,char **argc){
	ifstream ifile(argc[1]);
	string line;
	while (getline(ifile, line)){
		int i;
		stringstream ss(line);
		while (ss >> i){
			cout << minCoin(i) << endl;
		}
	}
	return 0;
}