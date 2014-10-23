#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int fibonacci(int a){
	int result = 0;
	if (a == 0){
		return 0;
	}
	else if (a == 1){
		return result = 1;
	}
	else if (a == 2){
		return result = 1;
	}
	else if (a == 3){
		return result = 2;
	}
	else {
		result = fibonacci(a-1) + fibonacci(a - 2);
	}
	return result;
}
int main(int argc,char **argv){
	ifstream file(argv[1]);
	string line;
	int answer;
	while (getline(file,line)){
		int a = 0;
		istringstream iss(line);
		while (!(iss >> a)){
			break;
		}
		answer = fibonacci(a);
		cout << answer << endl;
	}
	return 0;
}