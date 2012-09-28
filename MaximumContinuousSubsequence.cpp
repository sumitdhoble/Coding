#include<iostream>

// http://people.csail.mit.edu/bdean/6.046/dp/ problem 1

using namespace std;

int findMaximumSumSubsequence(int ARR[], int length);

int main(){

	int ARR[] = {1,3,2,6,-4,8,19,1,-20,4,-101};
	int LENGTH = 0, i = 0;

	for(i = 0; ; i++)
		if(ARR[i] == -101)
			break;

	LENGTH = i;
	
	cout << findMaximumSumSubsequence(ARR,LENGTH) << endl;

}

int findMaximumSumSubsequence(int ARR[], int length){

	int sum[length][length];

	int i,j,k;

	for(i = 0; i < length; i++)
		for(j = 0; j < length; j++){	
			if(i == j){
				sum[i][j] = ARR[i];
			}
			else
				sum[i][j] = 0;
		}

	for(i = 1; i < length; i++)
		for( j = 0; j < i; j++){
			sum[j][i] = sum[j][i-1] + ARR[i]; 
		}

	int max = 0, I = 0, J = 0;
	for(i = 0; i < length	; i++)
		for( j = 0; j < i; j++){
			if(sum[j][i] > max){
				max = sum[j][i];
				I = i;
				J = j;
			} 			
		}

	cout << I << " " << J << endl;
	return max;
}


