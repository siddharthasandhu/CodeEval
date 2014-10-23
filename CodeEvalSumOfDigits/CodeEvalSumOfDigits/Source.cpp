#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void checkSum(int a){
	string i = to_string(a);
	char const *pchar = i.c_str();
	int result = 0;
	while (*pchar != '\0'){
		char a = *pchar;
		int ia = a - '0';
		result = result + ia;
		pchar++;
	}
	cout << result << endl;
}

int main(/*int argv, char **argc*/){
	ifstream file("test.txt");
	string line;
	int a;
	while (getline(file, line)){
		istringstream iss(line);
		while (!(iss >> a)){
			break;
		}
		checkSum(a);
	}
	return 0;
}