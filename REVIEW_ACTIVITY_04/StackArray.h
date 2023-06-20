#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <stdbool.h>

#define MAX 20

typedef int Data;

typedef struct {
	Data data[MAX];
	int top;
} stack;

void initStack(stack *A);
bool isEmpty();
bool isFull();
void pop(stack *A); //delete
void push(stack *A, Data variable); //insert
Data peek(stack A); // use this to check the top
void display(stack A);
void visualize(stack A);


#endif
