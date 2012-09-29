#include<iostream>

/*
For bit strings X = x1 . . . xm, Y = y1 . . . yn and Z = z1 . . . zm+n, we say that Z is
an interleaving of X and Y if it can be obtained by interleaving the bits in X and Y
in a way that maintains the left-to-right order of the bits in X and Y . For example
if X = 101 and Y = 01 then x1x2y1x3y2 = 10011 is an interleaving of X and Y ,
whereas 11010 is not. Give the most eﬃcient algorithm you can to determine if Z
is an interleaving of X and Y . Prove your algorithm is correct and analyze its time
complexity as a function m = |X| and n = |Y |.
*/

using namespace std;

int main(){
	char X[] = {'3','1','0','1','2'}; // 3 is filler variable to ease the program by making index start from 1, 2 is end of string demarcation.
	char Y[] = {'3','0','1','2'};
	char Z[] = {'3','1','0','0','1','1','2'};

	int lX = 0,lY = 0,lZ = 0;
	int i = 0, j = 0, k = 0;
	
	for(i = 1; ; i++)
		if(X[i] == '2')
			break;
	lX = i-1;
	for(i = 1; ; i++)
		if(Y[i] == '2')
			break;
	lY = i-1;
	for(i = 1; ; i++)
		if(Z[i] == '2')
			break;
	lZ = i-1;
 
	//cout << lZ << " " << lX << " " << lY << endl;
	int construct[lZ+1][lX+1][lY+1];

	for(i = 0; i <= lZ; i++)
		for(j = 0; j <= lY; j++)
			for(k = 0; k <= lZ; k++)
				construct[i][j][k] = 0;

	if(Z[1] == X[1])
		construct[1][1][0] = 1;
	if(Z[1] == Y[1])
		construct[1][0][1] = 1;

	if(construct[1][1][0] != 1 && construct[1][0][1] != 1)
		cout << "Interleaving not possible" << endl;

	for(i = 2; i <= lZ; i++)
		for(j = 0; j <= i; j++)
			for(k = 0; k <= i; k++){
				if(i-1 > 0 && j-1 >= 0 && j <= lX && k <= lY && construct[i-1][j-1][k] == 1 && Z[i] == X[j] && construct[i][j][k] == 0){
					//cout << i << " " << j << " " << k << endl;
					construct[i][j][k] = 1;
				}
				if(i-1 > 0 && k-1 >= 0 && k <= lY && j <= lX && construct[i-1][j][k-1] == 1 && Z[i] == Y[k] && construct[i][j][k] == 0){
					//cout << i << " " << j << " " << k << endl;
					construct[i][j][k] = 1; 
				}
			}

	if(construct[lZ][lX][lY] == 1)
		cout << "Hurray!! Interleaving found" << endl;
	else
		cout << "No interleaving found" << endl;

	return 0;
}
