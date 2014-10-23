#include <stdlib.h	>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <iostream>


using namespace std;

typedef struct listnode{
	listnode *next;
	char obj;
} node;

void iterKList(int k, node *firstnode){
	node *fastRunner;
	node *slowRunner = firstnode;
	fastRunner = firstnode;
	int count = 0;
	while (fastRunner){
		fastRunner = fastRunner->next;
		if (count >= k){
			slowRunner = slowRunner->next;
		}
		count ++;
	}
	if (k <= count){
		cout << slowRunner->obj << endl;
	}
	else{
		return;
	}
}

void addNode(node **head,char s){
	if (*head == NULL){
		node *temp = (node *)malloc(sizeof(node));
		temp->obj = s;
		temp->next = NULL;
		*head = temp;
	}
	else {
		node *iter = *head;
		node *temp = (node *)malloc(sizeof(node));
		temp->obj = s;
		if (iter->next != NULL){
			while (iter -> next){
				iter = iter->next;
			}
		}
		iter->next = temp;
		iter = temp;
		iter->next = NULL;
	}
}

int processData(node **head, string line){
	int count = 0;
	stringstream ss(line);
	char i;
	int n;
	while (ss >> i){
		addNode(head, i);
		if (ss.peek() == ' '){
			ss.ignore();
		}
		if (isdigit(ss.peek()) ){
			ss >> n;
			return n;
		}
	}
	return 0;
}
int main(int argv,char **argc) {
	ifstream ifp(argc[1]);
	string line;
	while (getline(ifp,line)){
		node *HEAD = NULL;
		int number = processData(&HEAD,line);
		iterKList(number, HEAD);
	}
	return 0;
}
