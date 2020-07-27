#pragma once
#include <fstream>

using namespace std;

struct QNode
{
	int data;
	struct QNode *next;
};

struct Queue
{
	struct QNode *front, *rear;
};

QNode* newNode(int data);

Queue *create();

void push(Queue *q, int data);

QNode *pop(Queue *q);

int front(Queue *q);

char isEmpty(Queue *q);

void print(Queue *q, ofstream &fout);