#include<iostream>

using namespace std;

void reverseString(char *str, int n);

int main(){
	char str[] = {'m','y',' ','n','a','m','e',' ','i','s',' ' ,'s','u','m','i','t'};

	reverseString(str,16);
}

void reverseString(char *str, int n){
	int start = 0;
	int end = n-1;
	char c;
	int i=0,j=0;
	int flag = 0;

	while(start < end){
		c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}

	start = 0;
	while(true){
		end = start+1;
		while(str[end] != ' ' && end < n) {
		 end++;
		 if(end >= n) {
				flag = 1;
				break;
			}
		}
		end--;
		i = start;
		j = end;
		while(i<j){
			c = str[i];
			str[i] = str[j];
			str[j] = c;
			i++;
			j--;
		}
		start = end+2;

		if(flag == 1) break;
	}

	for(int i=0; i<n; i++)
		cout << str[i];

	cout << endl;
}
