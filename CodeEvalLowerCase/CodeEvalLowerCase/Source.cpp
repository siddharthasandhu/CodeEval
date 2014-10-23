#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void convertToLower(char *p){
	char *temp;
	temp = p;
	while (*temp != '\n'){
		char c = *temp;
		putchar(tolower(c));
		temp++;
	}
	cout << endl;
}

int main(/*int argc, char **argv*/){
	FILE *file;
	char line[1024];
	errno_t err = fopen_s(&file,"test.txt", "r");
	if (file == NULL){
		cout << "Failure";
		exit(0);
	}
	while (fgets(line,sizeof(line),file)){
		convertToLower(line);
	}
	return 0;
}