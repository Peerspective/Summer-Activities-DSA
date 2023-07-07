#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "StackQueueCB.h"



Date createDate(int date, int month, int year){
	Date A;
		A.date = date;
		A.month = month;
		A.year = year;
	return A;
}

Product createProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp){
	Product P;
	
	P.prodID = prodID;
	strcpy(P.prodName, prodName);
	P.prodQty = prodQty;
	P.prodPrice = prodPrice;
	P.prodExp = prodExp;
	
	return P;
}
VirtualSpace newVirtualSpace(){
	int i;
	VirtualSpace A;
	
	for(i=0; i<MAX; i++){
		A.data[i].items = createProduct(0, " ", 0, 0.00, createDate(0,0,0));
		A.data[i].link = i-1;
	}
	A.avail = MAX-1;
	
	return A;
}

int allocVspace(VirtualSpace* A){
	int retVal = A->avail;
	
	if(retVal != -1){
		A->avail= A->data[A->avail].link;
	}
	
	return retVal;
}

void deallocVspace(VirtualSpace* A, int index){
	if(index != -1 && index<MAX){
		A->data[index].link = A->avail;
		A->data[index].items = createProduct(0, " ", 0, 0.00, createDate(0,0,0));
		A->avail = index;
	}
}

void initQueue(Queue *Q){
		Q->front = -1;
		Q->rear = -1;
}
bool isEmptyQueue(Queue Q){
	bool retVal = false;
	if(Q.front == -1){
		retVal = true;
	}
	
	return retVal;
}
bool isFullQueue(VirtualSpace A){
	bool retVal = false;
	if(A.avail == -1){
		retVal = true;
	}
	
	return retVal;
}
void enqueue(VirtualSpace* A, Queue *Q, Product P){
	if(!isFullQueue(*A)){
		if(Q->front == -1 && Q->rear == -1){ //if first time executed
			Q->front = A->avail;
			Q->rear = A->avail;
			
			A->avail = A->data[A->avail].link;
			
			A->data[Q->front].items = P;
			A->data[Q->front].link = -1;
		}else {
			Q->rear = A->avail;
			
			A->avail = A->data[A->avail].link;
			
			A->data[Q->rear].items = P;
			A->data[Q->rear].link =  -1;
			A->data[Q->front].link = Q->rear;
		}
	}
}

int dequeue(VirtualSpace* A, Queue *Q){
//	if(!isEmpty()){
//		
//	}
}
int front(VirtualSpace* A, Queue *Q);



void initStack(StackList* S){
	*S = -1;
}
void push(VirtualSpace* A, Product P);
Product pop(VirtualSpace* A);
Product peek(VirtualSpace A, Product P);
bool isEmptyStack(VirtualSpace A, StackList Q);
bool isFullStack(VirtualSpace A, StackList Q);

void displayQueue(VirtualSpace A, Queue Q);
void displayStack(VirtualSpace A, StackList S);
void visualizeVspace(VirtualSpace A){
	int i;
	printf("------------VSPACE------------\n");
	printf("%5s  | %10s  | %5s\n" , "INDEX", "DATA", "NEXT");
	for(i = 0; i<MAX; i++){
		printf("%5d  | %10s  | %5d\n" , i, A.data[i].items.prodName, A.data[i].link);
	}
	printf("Avail Index : %d", A.avail);
}
