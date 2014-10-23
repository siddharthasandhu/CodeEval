#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char **argv){
	stack<string> list;
	ifstream ifile(argv[1]);
	string line;
	while (!ifile.eof()){
		getline(ifile, line);
		stringstream ssin(line);
		while (ssin.good()){
			string s;
			ssin >> s;
			list.push(s);
		}
		while (!list.empty()){
			cout << list.top() << " ";
			list.pop();
		}
		cout << endl;
	}
	getchar();
	return 0;
}