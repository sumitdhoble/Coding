#include<iostream>

/*
You have a set of n integers each in the range 0 ... K. 
Partition these integers into two subsets such that you minimize |S1 - S2|, where S1 and S2 denote the sums of the elements in each of the two subsets.
*/

using namespace std;

int Partition(int input[], int n, int a[], int aSize, int b[], int bSize);

int main(){

	int input[] = {1,20,30,4,14,-1001};
	int i = 0, j = 0;
	int n = 0, max = 0;
	int index1 = 0, index2 = 0;
	
	for(i = 0; ; i++)	{
		if(input[i] == -1001)
			break;
		max += input[i];
	}

	n = i;

	int dp[n][max+1];

	for(i = 0; i < n ; i++)
		for(j = 0; j <= max; j++)
			dp[i][j] = 0;

	dp[0][input[0]] = 1;

	for(i = 1; i < n; i++)
		for(j = 0; j <= max; j++){
			if(dp[i-1][j] == 1){
				index1 = j + input[i];
				dp[i][index1] = 1;
				index2 = j - input[i];
				if(index2 < 0) 
					index2 *= -1;
				dp[i][index2] = 1;
			}
		}

	for(i = 0; i <= max; i++){
		if(dp[n-1][i] == 1)
			break;
	}

	cout << i << endl;

	return 0;
}
