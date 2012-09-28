#include<iostream>
using namespace std;

int Coins[] = {4,10,25,-1};

int minCoins(int amount, int unitCoins);

int main(){

	int i,j;
	
	for(i = 0 ; ; i++)
		if(Coins[i] == -1)
			break;

	int unitCoins = i;
	int amount = 41;
	int minCoinCount[amount+1];

	// dynamic programming solution
	int min;
	minCoinCount[0] = 0;
	for(i = 1; i <= amount; i++){
		minCoinCount[i] = 100000;
		for(j	=	0; j < unitCoins; j++){
			if( (i-Coins[j]) >= 0 &&  (minCoinCount[i] > (1 + minCoinCount[i-Coins[j]])) ){
					minCoinCount[i] = (1 + minCoinCount[i-Coins[j]]);
				}
		}
	}

	cout << amount << " " << minCoinCount[amount] << endl;
	return 0;
}


// recursive solution
int minCoins(int amount, int unitCoins){

	int i,j,k,l;
	int arr[unitCoins];

	for( i = unitCoins-1; i >= 0 ; i--)
		if(amount == Coins[i])
			return 1;

	int min = 100000, minIndex = 0;
	for(i = 0; i < unitCoins; i++){
			if(amount - Coins[i] > 0){
				arr[i] = minCoins(amount - Coins[i], unitCoins) + 1;
				if(min > arr[i]){
					min = arr[i];
					minIndex = i;
				}
			}
		}

	return min;	
}



