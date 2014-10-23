#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;


typedef struct StackMadeWithLinkedListNode{
	struct StackMadeWithLinkedListNode *next;
	int data;
}stack;

void push(stack **head, int data){
	stack *node = (stack *)malloc(sizeof(stack));
	if (!node){
		cout << "memory error";
		abort();
	}
	else {
		node->data = data;
		if (*head == NULL){
			node->next = NULL;
			*head = node;
		}
		else {
			node->next = *head;
			*head = node;
		}
	}
}

void pop(stack **head){
	if (*head == NULL){
		cout << "stack is alread empty";
		abort();
	}
	else {
		stack *top;
		top = *head;
		*head = top->next;
		top->next = NULL;
		free(top);
	}
}



int main(int argv, char **argc){
	stack *head = NULL;
	ifstream file(argc[1]);
	string line;
	while (getline(file,line)){
		int count = 1;
		istringstream iss(line);
		int number;
		while (iss >> number){
			push(&head, number);
		}
		while (head != NULL){
			if (count % 2 != 0){
				cout << head->data << " ";
				pop(&head);
			}
			else {
				pop(&head);
			}
			count++;
		}
		cout << endl;
	}
	return 0;
}