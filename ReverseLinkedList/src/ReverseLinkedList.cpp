//============================================================================
// Name        : ReverseLinkedList.cpp
// Author      : SiddharthaSandhu
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct linkedListNode{
	char obj;
	linkedListNode *next;
}node;

void insertLinkedList(char *p,node **head){
	node *end = *head;
	while(*p != '\0'){
		node *temp = (node *)malloc(sizeof(node));
		temp -> obj = *p;
		end -> next = temp;
		end = temp;
		p++;
	}
    end->next = NULL;
}


void printList(node *head){
	node *temp = head;
	while(temp){
		cout << temp->obj << endl;
		temp = temp -> next;
	}
}

void reverseLinkedList(node **head){
	node *next;
	node *prev = NULL;
	node *current = *head;
	while (current){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main() {
	node *HEAD = (node *)malloc(sizeof(node));
	char p[] = "zangetsu";
	insertLinkedList(p,&HEAD);
	reverseLinkedList(&HEAD);
	printList(HEAD);
	return 0;
}
