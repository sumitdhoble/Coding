#include<iostream>
#include<stdlib.h>
#define N 4

using namespace std;

void rotateArray(int **, int n);

int main(){

	int i,j;

	int **arr;

	arr = (int **)malloc(sizeof(int *)*N);
	for(i = 0; i < N; i++)
		arr[i] = (int *)malloc(sizeof(int)*N);

	int arr2[][N] =
	{ { 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9,10,11,12 },
		{13,14,15,16 }
	};

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			arr[i][j] = arr2[i][j];
	}

	int **arr3 = arr;

	cout << "Original array : " << endl;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	rotateArray(arr, N);

	cout << endl <<  "Rotated array : " << endl;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			cout << arr3[i][j] << " ";
		cout << endl;
	}
	return 0;
}

void rotateArray(int **arr2, int n){

	int i = 0, j = 0;

	int **arr = arr2;

	int temp;
	int y1,y2,y3,y4;
	int x1,x2,x3,x4;

	if(n <= 0)
		return;

	n--;	

	j = 0;
	while(j < n){
		x1 = j;
		y1 = j;
		x2 = j;
		y2 = n;
		x3 = n;
		y3 = n;
		x4 = n;
		y4 = j;
		for(i = j; i < n; i++){
			temp = arr[x4][y4];
			arr[x4][y4] = arr[x3][y3];
			arr[x3][y3] = arr[x2][y2];
			arr[x2][y2] = arr[x1][y1];
			arr[x1][y1] = temp;
		
			y1++;
			x2++;
			y3--;
			x4--;
		}
		n--;
		j++;
	}
}

