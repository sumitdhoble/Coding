#include<iostream>

using namespace std;

typedef struct node {
	int value;
	int flag;
	node *next;
}node;

// Detects whether a linked list contains cycle. If yes, then the start node of that cycle is returned. If there is no cycle, NULL value is returned.
node *FindStartNodeOfCycle(node *head);

int main(){

	int i = 0, j = 0, k = 0;

	node list[6];
	node *head = NULL;
	node *startNodeOfCycle = NULL;
	
	list[0].value = 1;
	list[0].next = &list[1];	
	list[1].value = 2;
	list[1].next = &list[2];
	list[2].value = 3;
	list[2].next = &list[3];
	list[3].value = 4;
	list[3].next = &list[4];
	list[4].value = 5;
	list[4].next = &list[5];
	list[5].value = 6;
	list[5].next = &list[2];

	head = &list[0];
	startNodeOfCycle = FindStartNodeOfCycle(head);

	if(startNodeOfCycle != NULL)
		cout << startNodeOfCycle->value << endl;
	else
		cout << "No cycle in the list" << endl;

	return 0;
}

node *FindStartNodeOfCycle(node *head){

	node *single;
	node *twice;
	single = head;
	twice = head;
	int cycleSize = 1;
	
	while(single != NULL || twice != NULL){
		single = single->next;
		if(single == NULL)
			return NULL;
		twice = twice->next;
		if(twice == NULL)
			return NULL;
		twice = twice->next;
		if(twice == NULL)
			return NULL;
		if(single == twice)
			break;
	}

	if(single == NULL || twice == NULL)
		return NULL;

	while(1){		
		twice = twice->next;
		if(single == twice)
			break;		
		cycleSize++;
	}
	
	int i = 1;
	int found = 0;
	while(1){
		single->flag = 1;
		i = 1;
		found = 0;
		while(i < cycleSize){
			i++;
			single = single->next;
			if(single->flag != 1){
				found = 1;
				break;
			}
		}
		if(found == 0)
			break;
		single->flag = 1;
	}

	while(head->flag != 1)
		head = head->next;

	return head;
}
