#include<iostream>

using namespace std;

/*
O(n) solution to separate even numbers to the left and odd numbers to the right. Does not maintain original ordering i.e. is not stable.
*/

int main(){

	int array[] = {-1,1,5,2,6,71,26,87,3,7,-2};

	int i = 1, size = 0;

	while(array[i] != -2) i++;

	size = i-1;

	int ptr1 = 1, ptr2 = 1, temp = 0;

	while(ptr2 <= size && ptr1 <= size){
		while(array[ptr1] % 2 == 0 && ptr1 <= size)
			ptr1++;
		while(array[ptr2] % 2 != 0 && ptr2 <= size)
			ptr2++;
		if(ptr1 > size || ptr2 > size)
			break;
		temp = array[ptr1];
		array[ptr1] = array[ptr2];
		array[ptr2] = temp;
	}

	for(i = 1; i <= size; i++)
		cout << array[i] << " ";

	cout << endl;
}
