#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void swap(char *p, char *m){
	char temp;
	temp = *p;
	*p = *m;
	*m = temp;
}

void permutate(char *str, int i, int n){
	if (*str = NULL){
		cout << "Some Problem here";
		return;
	}
	int j;
	if (i == n){
		cout << str << ',';
	}
	else {
		for (j = 1; j <= n; ++j){
			swap(str+i,str+j);
			permutate(str,i+1,n);
			swap(str+i,str+j);
		}
	}
}

int main(int argc, char **argv){
	fstream ifile("test.txt");
	string line;
	while (getline(ifile, line)){
		char *str = const_cast<char *>(line.c_str());
		permutate(str, 0, 2);
	}
	return 0;
}