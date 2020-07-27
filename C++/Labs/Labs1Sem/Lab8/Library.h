#pragma once
#include <iostream>

// Stack.cpp
const char STR_SIZE = 100;

struct StackNode
{
	void *data;
	StackNode *next;
};

StackNode *newNode(void *data);

char isEmpty(StackNode *top);

void push(StackNode **top, void * data);

void *pop(StackNode **top);

void *peek(StackNode *top);

size_t size(StackNode *top);

// Calculator.cpp
int priority(char c);

char *toPostfix(char *str);

int calculate(char *str);