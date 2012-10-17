#include<iostream>

using namespace std;

typedef struct Node {
	int data;
	Node *next;
}Node;

void IterativeReverseLinkedList( Node **head) {
    
    Node *one;
		Node *two;
		Node *three;

		one = *head;
		two = one->next;
		if(two == NULL)
			return;
		three = two->next;
		if(three == NULL){
			two->next = one;
      (*head)->next = NULL;
      (*head) = two;
      return;
		}
    
    while(1){
				two->next = one;

				one = two;
				two = three;
				three =	three->next;

        if(three == NULL){
						two->next = one;
            (*head)->next = NULL;
            (*head) = two;
            break;
        }
    }
    
}    

Node *RecursiveReverseLinkedList( Node *node, Node **head ) {

    Node *originalHead = *head;

    if( node->next == NULL){				
        *head = node;
        return node;
    }

    Node *temp = RecursiveReverseLinkedList(node->next, head);

		temp->next = node;

    if(node == originalHead){
        node->next = NULL;
		}
    
    return node;
}


int main(){

	Node list[4];

	list[0].data = 1;
	
	list[1].data = 2;
	list[0].next = &list[1];

	list[2].data = 3;
	list[1].next = &list[2];

	list[3].data = 4;
	list[2].next = &list[3];
	list[3].next = NULL;

	Node *head = &list[0];

	Node *node = head;

	while(node != NULL){
		cout << node->data << " < ";
		node = node->next;
	}
	cout << endl;
	
	RecursiveReverseLinkedList(head, &head);

	node = head;
	while(node != NULL){
		cout << node->data << " < ";
		node = node->next;
	}
	cout << endl;
	
	return 0;
}


