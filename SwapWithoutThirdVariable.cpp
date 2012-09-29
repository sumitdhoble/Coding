#include<iostream>

using namespace std;

void swapWithoutThirdVariable(int *x, int *y);

int main(){

	int a = 10, b = 20;

	cout << a << " " << b << endl;
	swapWithoutThirdVariable(&a, &b);
	cout << a << " " << b << endl;

	return 0;
}

void swapWithoutThirdVariable(int *x, int *y){
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
