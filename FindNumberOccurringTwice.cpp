#include<iostream>

using namespace std;

int main(){
	
	int arr[] = {12,3,5,12,3,12,8,3,5,100,100,5,-1};	
	int x = 0, i = 0, one = 0, two = 0 ,notthree = 0;

	for(i = 0 ; ; i++){
		x = arr[i];
		if( x<0 ) break;
		two = two | (one & x) ;
		one ^= x;
		notthree = ~ ( one & two );
		one &= notthree;
		two &= notthree;
	}

	cout << two << endl;
}


