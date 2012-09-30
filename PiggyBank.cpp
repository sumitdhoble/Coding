#include<iostream>
using namespace std;

/*
You are given a piggy bank ﬁlled with coins. You need to
determine what the minimum amount of money is that
could be in the piggy bank.

You are given the the weight of the piggy bank.

You are also given a set of N coins with weight and value.
*/

// {value, weight} 
int Coins[][2] = { {3,2} , {10,5} ,{25,7} ,{-1,-1} };

int minCoins(int amount, int unitCoins);

int main(){

	int i,j;
	
	for(i = 0 ; ; i++)
		if(Coins[i][0] == -1)
			break;

	int N = i;
	int weight = 12; // minimum amount = 18
	int minAmount[weight+1];

	// dynamic programming solution
	int min;
	minAmount[0] = 0;
	for(i = 1; i <= weight; i++){
		minAmount[i] = 100000;
		for(j	=	0; j < N; j++){
			if( (i-Coins[j][1]) >= 0 &&  (minAmount[i] > Coins[j][0] + minAmount[i-Coins[j][1]]) ){
					minAmount[i] = (Coins[j][0] + minAmount[i-Coins[j][1]]);
				}
		}
	}

	cout << weight << " " << minAmount[weight] << endl;
	return 0;
}


