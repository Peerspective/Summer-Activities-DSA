#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list){
	*list = NULL;
}

List newList(){
	List A;
	
	initList(&A);
	
	return A;
	
}

NodeType createNode(DATA data){
	NodeType A;
	A.data = data;
	A.next = NULL;
	
	return A;
	
}

void displayList(List list){
	List trav;
	if(list != NULL){
		for(trav = list; trav != NULL; trav = trav->next){
			printf("%d ", trav->data);
		}
	}else printf("List is empty at the moment");
}

bool insertFront(List *list, DATA item){
	bool retBool = false;
	NodeType A = createNode(item);
	
	NodeType* B = (NodeType*)malloc(sizeof(NodeType));
	
	
	if(*list != NULL){
		B->data = A.data;
		B->next = *list;
		*list = B;
		retBool = true;
	}else {
		
		B->data = A.data;
		*list = B;
		retBool = true;
	}
}

bool insertRear(List *list, DATA item){
	bool retBool = false;
	NodeType A = createNode(item);
	List trav;
	if(*list != NULL){
		for(trav= *list; trav->next != NULL; trav=trav->next){}
		trav->next = &A;
		retBool = true;
	}else {
		
		*list = &A; 
		retBool = true;
	}
	return retBool;
}

bool insertAt(List *list, DATA item, int loc);

bool insertSorted(List *list, DATA data);

bool searchItem(List list, DATA key);

int getItem(List list, DATA key);

bool deleteFront(List *list);

bool deleteRear(List *list);

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
