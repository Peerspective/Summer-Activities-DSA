#ifndef STACKQUEUECB_H
#define STACKQUEUECB_H

#include <stdbool.h>
#define MAX 20

typedef char String[20];
typedef struct {
		int date;
		int month;
		int year;
}Date;

typedef struct {
		int prodID;
		String prodName;
		int prodQty;
		double prodPrice;
		Date prodExp;
}Product;

typedef struct {
		Product items;
		int link;
}SType;

typedef struct {
		SType data[MAX];
		int avail;
}VirtualSpace;

typedef int StackList;

typedef struct{
		int front;
		int rear;
}Queue;

Date createDate(int date, int month, int year);
Product createProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp);
VirtualSpace newVirtualSpace();
int allocVspace(VirtualSpace* A);
void deallocVspace(VirtualSpace* A, int index);

void initQueue(Queue *Q);
void enqueue(VirtualSpace* A, Queue *Q, Product P);
int dequeue(VirtualSpace* A, Queue *Q);
int front(VirtualSpace* A, Queue *Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(VirtualSpace A);


void initStack(StackList *S);
void push(VirtualSpace* A, Product P);
Product pop(VirtualSpace* A);
Product peek(VirtualSpace A, Product P);
bool isEmptyStack(VirtualSpace A, StackList Q);
bool isFullStack(VirtualSpace A, StackList Q);

void displayQueue(VirtualSpace A, Queue Q);
void displayStack(VirtualSpace A, StackList S);
void visualizeVspace(VirtualSpace A);

#endif
