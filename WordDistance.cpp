#include<iostream>

using namespace std;

int minDistance(string word1, string word2);

int main(){

	string word1 = "dog";
	string word2 = "fogt";

	int dist = minDistance(word1, word2);

	cout << dist << "\n";

}

int minDistance(string word1, string word2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

		// cout << word1 << endl << word2 << endl;

		if(word1.length() == 0)
			return word2.length();

		if(word2.length() == 0)
			return word1.length();
    
  	if(word1.at(0) == word2.at(0))
			return minDistance(word1.substr(1), word2.substr(1));

		int i = minDistance(word1.substr(1), word2) + 1;

		int j = minDistance(word1.substr(1), word2.substr(1)) + 1;

		int k = minDistance(word1, word2.substr(1)) + 1;

		if( i < j )
			if( i < k )
				return i;
			else 
				return k;
		else
			if( j < k )
				return j;
			else
				return k;
}
