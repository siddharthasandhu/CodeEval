#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


typedef struct LinkedListNode{
	struct LinkedListNode *next;
	int obj;
}node;

void addNode(node **head, int s){
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
			while (iter->next){
				iter = iter->next;
			}
		}
		iter->next = temp;
		iter = temp;
		iter->next = NULL;
	}
}

void reverseList(node **head){
	node *prev = NULL;
	node *current = *head;
	node *next;
	while (current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}
node *breakList(node **head, int breaker){
	node *temp = *head;
	node *secList,*firstList;
	firstList = *head;
	int count = 1;
	while (temp){
		if (count < breaker){
			temp = temp->next;
			count++;
		}
		else {
			secList = temp->next;
			temp->next = NULL;
			reverseList(&firstList);
			secList = breakList(&secList, breaker);
			node *newTemp;
			newTemp = firstList;
			while (newTemp->next!=NULL){
				newTemp = newTemp->next;
			}
			newTemp->next = secList;
			break;
		}
	}
	return firstList;
}
int processData(node **head,string line){
	int count = 0;
	stringstream ss(line);
	int i;
	while (ss >> i){
		if (count != 0){
			return i;
		}
		addNode(head,i);
		if (ss.peek() == ','){
			ss.ignore();
		}
		else if (ss.peek() == ';'){
			count = 1;
			ss.ignore();
		}
	}
	return 0;
}
void printList(node *head){
	node *temp = head;
	while (temp){
		if (temp->next == NULL){
			cout << temp->obj;
		}
		else {
			cout << temp->obj << ",";
		}
		temp = temp->next;
	}
	cout << endl;
}
int main(int argc, char **argv){
	ifstream file(argv[1]);
	string line;
	int switchNo = 0;
	while (getline(file, line)){
		node *HEAD = NULL;
		node *TAIL = NULL;
		switchNo = processData(&HEAD, line);
		HEAD = breakList(&HEAD, switchNo);
		printList(HEAD);
	}
	return 0;
}