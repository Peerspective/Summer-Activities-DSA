#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularQ.h"


void initQueue(Queue *q){
	q->front = 7;
	q->rear = 6;
	int i;
	for( i = 0; i <MAX; ++i){
		q->elems[i] = EMPTY;
	}
}
void enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX; //check if it is not full
		q->elems[q->rear] = item;
	}
}
int dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->elems[q->front] = EMPTY;
		q->front  = (q->front + 1)% MAX;
	}
}
int front(Queue q){
	if(!isEmpty(q)){
		return q.elems[q.front];
	}
	return EMPTY;
}
bool isEmpty(Queue q){
	return (q.rear +1)%MAX == q.front;
}
bool isFull(Queue q){
	return (q.rear+2)%MAX == q.front;
}

void visualize(Queue q){
	int i;
	printf("%5s | %5s | %5s\n", "INDEX", "VALUE", "POSITION");
	printf("---------------------\n");
	
	for(i = 0; i< MAX; ++i){
		printf("\n%5d | ", i);
		if(q.elems[i] != EMPTY){
			printf("%5d | ", q.elems[i]);
		} else {
			printf("%5s | ", " ");
		}
		
		if(i == q.front){
				printf("FRONT");
		}
		if( i == q.rear){
				printf("REAR");
		} 
	}
}
void display(Queue q) {
	int i;
	printf("%5s | %5s | %5s\n", "INDEX", "VALUE", "POSITION");
	printf("---------------------\n");
	
		for(i = q.front; (i)%MAX != (q.rear+1)%MAX ;i = (i+1)%MAX){
			printf("\n%5d | ", i);
			if(q.elems[i] != EMPTY){
				printf("%5d | ", q.elems[i]);
			} 
			
			if(i == q.front){
					printf("FRONT");
			}
			if( i == q.rear){
					printf("REAR");
			} 
		}
}
bool removeItem(Queue *q, int item){
	
	
}
Queue removeEven (Queue *q){
	

} //removes all even and returns all delete item stored in Q.
int doubleTheValue(Queue *q, int value); // doubles the value in Q that is a mutliple of the given value and return how many values have been change.



