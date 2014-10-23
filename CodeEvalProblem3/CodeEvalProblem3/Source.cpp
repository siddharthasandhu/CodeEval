#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

typedef struct LinkedListNode{
	struct LinkedListNode *next;
	int data;
} node ;

void insertData(node **head,int data){
	node *p;
	p = *head;
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	if (p->next == NULL){ 
		p->next = temp;
		p->next->next = NULL;
	}
	else{
		temp->next = p->next;
		p->next = temp;
	}
}

void removeNode(node* rem){
	node *temp;
	if (rem->next != NULL){
		rem->data = rem->next->data;
		temp = rem->next;
		rem->next = temp->next;
		free(temp);
	}
	else {
		rem ->data =  -1 ;
	}
}
void seiveOfEras(node *head){
	node *temp1 = head -> next;
	node *temp2;
	while (temp1){
		int div = temp1->data;
		temp2 = temp1->next;
		while (temp2){
			if (temp2->data%div == 0){
				removeNode(temp2);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
void showResult(node *head){
	node *temp = head ->next;
	long result = 0;
	while (temp && !(temp ->data < 0) ){
		if (temp->next->next != NULL){
			cout << temp->data << ",";
		}
		else {
			cout << temp->data;
		}
		temp = temp->next;
	}
	cout << endl;
}
int main(int argv,char **argc){
	ifstream file(argc[1]);
	string line;
	while (getline(file, line)){
		int a;
		istringstream iss(line);
		while (!(iss >> a)){
			break;
		}
		node *head = (node *)malloc(sizeof(node));
		head->next = NULL;
		head->data = 1;
		for (int i = a; i >= 2; i--){
			insertData(&head, i);
		}
		seiveOfEras(head);
		showResult(head);
	}
	getchar();
	return 0;
}