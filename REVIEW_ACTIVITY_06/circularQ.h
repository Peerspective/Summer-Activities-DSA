#ifndef CIRCULARQ_H
#define CIRCULARQ_H

#define EMPTY 9999
#include <stdbool.h>
#define MAX 10

typedef char String[20];
typedef struct {
	int elems[MAX];
	int front;
	int rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void visualize(Queue q);
void display(Queue q);
bool removeItem(Queue *q, int item); //first occurence <- Use only the queue operators no element traversals
Queue removeEven (Queue *q); //removes all even and returns all delete item stored in Q.
int doubleTheValue(Queue *q, int value); // doubles the value in Q that is a mutliple of the given value and return how many values have been change.

#endif
