#include<iostream>

// longest common subsequence

int longestIncreasingSubsequence (int arr[], int ptr, int ptr2, int n);

using namespace std;

int main(){

	int ARR[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15,-1};
	int LENGTH = 0;
	
	for(int i = 0; ; i++){
		if(ARR[i] == -1){
			LENGTH = i;
			break;
		}
		else{
			i++;
		}
	}

	int LCS[LENGTH]; 
	int PREV[LENGTH];
	int maxIndex = 0;
	int lcs = 0;
	int flag = 0;
	
	LCS[0] = 1;
	PREV[0] = -1;

	for(int i = 1; i < LENGTH; i++){
		
		maxIndex = 0;
		flag = 0;
		for(int j = 0; j < i; j++){
			if(ARR[i] > ARR[j]){
				flag = 1;
				if(LCS[j] >= LCS[maxIndex]){
					 maxIndex = j;
				  }
			}
		}
		if(flag == 1){
			PREV[i] = maxIndex;
			LCS[i] = LCS[maxIndex] + 1;		
		}else if(flag == 0){
			PREV[i] = -1;
			LCS[i] = 1;
		}
	}

	maxIndex = 0;
	lcs = LCS[0];
	for(int i = 1; i < LENGTH; i++){
		if(LCS[i] >= lcs){
			lcs = LCS[i];
			maxIndex = i;
		}		
	}

	cout << "Length of longest increasing subsequence = " << lcs << endl;

	int LongestIncreasingSubsequence[lcs];
	int j = lcs-1;
	int i;
	for(i = maxIndex ; ; j--){
		if(i == -1)	
			break;		
		LongestIncreasingSubsequence[j] = ARR[i];
		i = PREV[i];
	}

	for(i = 0; i < lcs ; i++)
		cout << LongestIncreasingSubsequence[i] << " " ;
	cout << endl;
}

/*
int longestIncreasingSubsequence (int arr[], int ptr, int ptr2, int n)
{
	int flag = 1;

	if(ptr >= LENGTH){
		return n;
	}

	if(n >= 1 && arr[ptr] <= arr[ptr2]){
		return longestIncreasingSubsequence(arr,ptr+1,ptr2,n);
	}

	int l = longestIncreasingSubsequence(arr,ptr+1,ptr2,n);
	
	ptr2 = ptr;
	n++;
	ptr++;
	int k = longestIncreasingSubsequence(arr,ptr,ptr2,n);

	if(l > k)
		return l;
	else
		return k;		
}
*/
