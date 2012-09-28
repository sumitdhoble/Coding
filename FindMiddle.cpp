#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
int data;
node *next;
}node;

void printNodes(node *curr);
void reverseNodes(node **head);
void printMiddle(node *head);

int main()
{
  node *head;
	node nodes[6];
  head = (node *)malloc(sizeof(node));
  head->next = &nodes[0];
	head->data = 0;
  nodes[0].next = &nodes[1];
  nodes[0].data = 1;
	nodes[1].next = &nodes[2];
  nodes[1].data = 2;
  nodes[2].next = &nodes[3];
	nodes[2].data = 3;
  nodes[3].next = &nodes[4];
	nodes[3].data = 4;
  nodes[4].next = NULL;
	nodes[4].data = 5;
	nodes[5].next = NULL;
	nodes[5].data = 6;

	cout << "Original linked list : " << endl;
	printNodes(head);
	reverseNodes(&head);
	cout << "Reverse linked list : " << endl;
  printNodes(head);

	cout << "Middle element of the linked list : ";
	printMiddle(head);

  return 0;
}

void reverseNodes(node **head){
	node *curr;
	node *currNext;
	node *holder;

	curr = *head;
	if(curr == NULL)
		return;
  currNext = curr->next;
	if(currNext == NULL)
		return;
  curr->next = NULL;

	while(currNext != NULL && curr != NULL){
		holder = currNext->next;
		currNext->next = curr;
    curr = currNext;
    currNext = holder;
  }

	*head = curr;
}

void printMiddle(node *head){
	node *curr;
	node *doubleCurr;

	curr = head;
	doubleCurr = head;

	while(curr != NULL && doubleCurr != NULL){		
		doubleCurr = doubleCurr->next;
		if(doubleCurr == NULL)
			break;
		curr = curr->next;
		doubleCurr = doubleCurr->next;
	}

	if(curr != NULL)
		cout << curr->data << "\n";
}

void printNodes(node *curr){
	while(curr != NULL){
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}
