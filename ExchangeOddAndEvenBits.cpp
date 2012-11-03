#include<iostream>

using namespace std;

int main(){
	int num, i, j;
	cin >> num;
	i = num & 0x5555555;
	i = i << 1;
	j = num & 0xaaaaaaa;
	j = j >> 1;
	num = i | j;
	cout << num << endl;
}
