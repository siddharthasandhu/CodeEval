#include <iostream>

using namespace std;

int Line(int x0, int y0, int x1, int y1){
	int dx = (x1 - x0);
	int dy = (y0 - y1);
	int d = 2 * (dy - dx);
	int delE = 2 * dy, delNE = 2 * (dy - dx);
	int x = x0, y = y0;
	cout << x <<","<< y << endl;

	while (x < x1){
		if (d <= 0){
			d += delE; x = x + 1;
		}
		else{
			d += delNE; x = x + 1; y = y - 1;
		}
		cout << x << "," << y << endl;
	}
	getchar();
	return 0;
}

int main(){
	Line(2,8,5,4);
	return 0;
}
