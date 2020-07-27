#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

QNode* newNode(int data)
{
	QNode *temp = new QNode;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Queue *create()
{
	Queue *q = new Queue;
	q->front = q->rear = NULL;
	return q;
}

void push(Queue *q, int data)
{
	struct QNode *temp = newNode(data);

	if (q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

QNode *pop(Queue *q)
{
	if (q->front == NULL)
		return NULL;

	QNode *temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;
	return temp;
}

int front(Queue *q)
{
	return q->front->data;
}

char isEmpty(Queue *q)
{
	if (q->front == NULL)
		return true;
	else
		return false;
}

void print(Queue *q, ofstream &fout)
{
	while (!isEmpty(q)) {
		fout << front(q) << " ";
		pop(q);
	}
}