#include<iostream>

using namespace std;

/*
	 5,  2,  4,  7,  9
	11, 15, 14,  6,  9
	12, 32,  5,  3, 19
	59, 23, 25, 75,  2
	 3,  4,  7, 10,  5
*/

int main()
{
	int m = 5, n = 5;
	int a[5][5] = { {5,2,4,7,9} , {11,15,14,6,9} , {12,32,5,3,19}, {59,23,25,75,2}, {3,4,7,10,5}};

	int i = 0,j = 0,k = 0,l = 0;
	int limit1 = 0, limit2 = 0;
	

	if(n % 2 == 0)
		limit1 = n/2;
	else
		limit1 = n/2 + 1;

	if(m % 2 == 0) 
		limit2 = m/2;
	else
		limit2 = m/2+1;

	for(i = 0; ; i++){
		if(i+1 > limit1 || i+1 > limit2)
			break;
		for(j = i; j < n-i; j++)
			cout << a[i][j] << " ";
		j--;
		for(k = i+1; k < m-i; k++)
			cout << a[k][j] << " ";
		k--;
		j--;
		for( ; j >= i && k > i; j--)
			cout << a[k][j] << " ";
		j++;
		k--;
		for( ; k > i; k--)
			cout << a[k][j] << " ";
	}

	cout << endl;
	
	return 0;
}
