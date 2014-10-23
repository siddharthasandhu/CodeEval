#include <iostream>

using namespace std;


int main(){
	int number = 99;
	for (int i = 0; i <= number; i++){
		if (i % 2 != 0){
			cout << i << endl;
		}
	}
	return 0;
}