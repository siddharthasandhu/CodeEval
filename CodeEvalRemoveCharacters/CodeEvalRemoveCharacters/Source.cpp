#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>


using namespace std;

int main(int argv, char **argc){
	ifstream file("text.txt");
	string line;

	while (getline(file, line)){
		stack<char> par;
		stringstream ss(line);
		char i;
		int count = 0;
		while (ss >> i){
			if (i == '{'){
				par.push('{');
			}
			else if (i == '('){
				par.push('(');
			}
			else if (i == '['){
				par.push('[');
			}
			if (i == '}'){
				if (!par.empty()){
					if (par.top() == '{'){
						par.pop();
					}
					else{
						count = 1;
						break;
					}
				}
				else {
					count = 1;
					break;
				}
			}
			else if (i == ')'){
				if (!par.empty()){
					if (par.top() == '('){
						par.pop();
					}
					else{
						count = 1;
						break;
					}
				}
				else {
					count = 1;
					break;
				}
			}
			else if (i == ']'){
				if (!par.empty()){
					if (par.top() == '['){
						par.pop();
					}
					else{
						count = 1;
						break;
					}
				}
				else {
					count = 1;
					break;
				}
			}
		}
		if (count != 1 && par.empty()){
			cout << "True" << endl;
		}
		else if (!par.empty() || count == 1){
			cout << "False" << endl;
		}
	}
	getchar();
	return 0;
}