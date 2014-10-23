#include <iostream>

using namespace std;

typedef struct QNode{
	struct QNode *next, *prev;
	unsigned pagenumber;
}QNode;

typedef struct Queue{
	unsigned count;
	unsigned numberOfFrames;
	QNode *front, *rear;
}Queue;

typedef struct Hash{
	unsigned count;
	QNode* *array;
}hash;


bool allFramesFull(Queue *queue){
	return (queue->numberOfFrames = queue->count);
}

bool isQueueEmpty(Queue *queue){
	return (queue->rear = NULL);
}


Queue *createQueue(int numberOfFrames){
	Queue *temp = (Queue *)malloc(sizeof(Queue));
	if (!temp){
		cout << "Problem in createQueue";
		return 0;
	}
	temp->count = 0;
	temp->numberOfFrames = numberOfFrames;
	temp->front = temp->rear = NULL;
	return temp;
}
void deQueue(Queue *queue){
	if (isQueueEmpty(queue)){
		cout << "no element in queue";
		return;
	}
	if (queue->front = queue->rear){
		queue->front = NULL;
	}
	QNode *temp = queue->rear;
	queue->rear = queue->rear->prev;
	if (queue->rear){
		queue->rear->next == NULL;
	}
	free(temp);
	queue->count--;
}

void Enqueue(Queue *queue, unsigned data){
	if (allFramesFull(queue)){
		cout << "No more data can be inserted";
		return;
	}
	QNode *temp = (QNode *)malloc(sizeof(QNode));
	temp->next = NULL;
	temp->next = queue->front;
	if (isQueueEmpty(queue)){
		queue->rear = queue->front = temp;
	}
	else{
		queue->front->prev = temp;
		queue->front = temp;
	}
	queue->count++;
}