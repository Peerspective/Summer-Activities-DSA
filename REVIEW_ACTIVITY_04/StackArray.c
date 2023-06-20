#include <stdio.h>
#include <stdlib.h>

#include "StackArray.h"


void initStack(stack *A){
	A->top = 0;
}

bool isEmpty(stack A){
	bool Empty = false;
	if(A.top <= 0){
		Empty = true;
	}
	
	return Empty;
}
bool isFull(stack A){
	bool Full = false;
	if(A.top >= MAX){
		Full = true;
	}
	
	return Full;
}

void pop(stack *A){ //delete
	bool answer = isEmpty(*A);
	if( answer != true) {
		A->top--;
	}
}
void push(stack *A, Data variable){ //insertLast
	if(isFull(*A) != true){
		A->data[A->top++] = variable;
	}else printf("List is full");
}

Data peek(stack A){ // use this to check the top
	Data data;
	if(isEmpty(A) != true){
		data = A.data[A.top];

	}
	
	return data;
}
void display(stack A){
	stack B;
	initStack(&B);
	int value;
	int i;
//	printf("A.top = %d", A.top);
	for(i=0; i<=A.top+1; i++){
		value = peek(A); 
		if(isFull(B) != true ){
			push(&B, value);
		}
		if(isEmpty(A) != true){
			pop(&A);
			
			printf("%d ", A.data[A.top]);
		}
	}
}
void visualize(stack A){
	int i;
	for(i = A.top-1; i >= 0; i--){
		printf("%d ", A.data[i]);
	}
}
