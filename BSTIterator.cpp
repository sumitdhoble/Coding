#include<iostream>

using namespace std;

typedef struct Node {
	int value;
	Node *left;
	Node *right;
}Node;

class Iterator {

private : 
	Node *curr, *max, *root;
	bool flag;
public :
	Iterator(Node *);
	bool hasNext();
	Node * getNext();

};

Iterator::Iterator(Node *r){
	if(r == NULL)
		return;
	curr = r;
	max = r;
	root = r;
	flag = false;
	while(max->right != NULL){
		max = max->right;
	}
	while(curr->left != NULL){
		curr = curr->left;
	}
}

bool Iterator::hasNext(){
	if(curr == NULL || max == NULL)
		return false;
	else if (curr->value < max->value){
		return true;
	}
	else if(curr-> value == max->value){
		if(flag == true)
			return false;
		else
			return true;
	}
}

Node *Iterator::getNext(){
	if(curr == NULL)
		return NULL;
	Node *rvalue = curr;
	if(curr->right != NULL){
		curr = curr->right;
		while(curr->left != NULL)
			curr = curr->left;
	}
	else{
		Node *r = root, *nextCurr = curr;
		while(r->value != curr->value){
			if(r->value < curr->value){
				r = r->right;
			}
			else{
				nextCurr = r;
				r = r->left;
			}
		}
		curr = nextCurr;
		
	}
	if(rvalue->value == max->value) 
		flag = true;
	return rvalue;
}

int main(){
	Node tree[10];

	tree[1].value = 1;
	tree[1].left = NULL;
	tree[1].right = NULL;
	tree[2].left = &tree[1];
	tree[2].right = &tree[4];
	tree[2].value = 2;
	tree[4].value = 4;
	tree[4].left = &tree[3];
	tree[4].right = &tree[5];
	tree[3].value = 3;
	tree[3].left = NULL;
	tree[3].right = NULL;
	tree[5].value = 5;
	tree[5].left = NULL;
	tree[5].right = NULL;


	Node *curr;
	Iterator it = Iterator(&tree[2]);
	while(it.hasNext()){
		curr = it.getNext();
		if(curr != NULL)
			cout << curr->value << endl;
	}

	return 0;;
}
