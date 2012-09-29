#include<iostream>

using namespace std;

void printZigZag(int a[][3], int m, int n);

int main()
{
	int a[5][3] = { 1,2,3,6,5,4,7,8,9,12,11,10,13,14,15};

	for(int i=0; i < 5; i++)
		for(int j=0; j < 3; j++)
			cout << a[i][j] << " " ;
	
	cout << endl;

	printZigZag(a, 5, 3);
}


void printZigZag(int a[][3], int m, int n){
	int i,j;
	int flag = 0;

	for(i = 0; i < m; i++){
		if(flag == 0){
			for(j = 0; j < n; j++)
				cout << a[i][j] << " ";
			flag = 1;
		}		
		else {
			for(j = n-1; j >= 0; j--)
				cout << a[i][j] << " ";
			flag = 0;
		}
	}

	cout << endl;
}

