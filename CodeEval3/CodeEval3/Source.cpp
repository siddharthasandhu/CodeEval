#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef struct LinkedListNode{
	struct LinkedListNode *next;
	int data;
	int pos;
} node;

int insertData(node **head, int data,int count){
	node *p = *head;
	node *temp = (node *)malloc(sizeof(node));
	if (p->pos == 0){
		p ->data = data;
		p->pos = 1;
		p->next = NULL;
		free(temp);
	}
	else {
		temp->data = data;
		temp->pos = (p->pos + 1);
		temp->next = p;
		*head = temp;
	}
	return p->pos;
}


bool checkPrime(node *head,int i){
	node *temp = head;
	int div = sqrt(i);
	if (i == 2){
		return 1;
	}
	else if (i == 3){
		return 3;
	}
	while (temp){
		if (i % temp->data != 0){
			temp = temp->next;
		}
		else return 0;
	}
	return 1;
}

int calSum(node *head){
	node *temp = head->next;
	long result = 0;
	while (temp){
		result = result + temp->data;
		temp = temp->next;
	}
	return result;
}
int main(){
	long sum;
	node *head = (node *)malloc(sizeof(node));
	head->pos = 0;
	int count = 1;
	int increment = 2;
	while (count < 1000){
		if (checkPrime(head,increment)){
			count = insertData(&head, increment,count);
		}
		increment++;
	}
	sum = calSum(head);
	cout << sum << endl;
	return 0;
}