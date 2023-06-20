#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StaticArray.h"

void initList(List *list){
	int i;
	for(i=0;i<MAX;i++){
		list->elems[i] = 0;
	}
	list->count = 0;
}

List newList(){
	List a;
	initList(&a);
	
	return a;
}

void displayList(List list){
	int i;
	printf("\n");
	for(i=0; i<list.count; i++){
		printf("%d ", list.elems[i]);
	}
}

bool insertFront(List *list, DATA item){
	bool returnStatement = false;
	int i;
	if(list->count<MAX){
		if(list->count != 0){
			for(i=list->count;i > 0; i--){
				list->elems[i] = list->elems[i-1];
			}
			list->elems[i] = item;
			list->count++;
			returnStatement = true;
		}else {
			list->elems[0] = item;
			list->count++;
		}
	}else printf("Cannot insert, storage already full!");
	
	return returnStatement;
}

bool insertRear(List *list, DATA item){
	bool returnStatement = false;
	if(list->count < MAX){
		list->elems[list->count] = item;
		list->count++;
		returnStatement = true;
	}else printf("Cannot insert, storage already full!");
	
	return returnStatement;
}

bool insertSorted(List *list, DATA item){
	bool returnStatement = false;
	int i;
	if(list->count < MAX){
		if(list->count != 0){
			for(i=list->count; list->elems[i-1] > item; i--){ //efficient?
				list->elems[i] = list->elems[i-1];
			}
			list->elems[i] = item;
			list->count++;
		}else list->elems[0] = item;
	}else printf("Cannot insert, storage already full!");
}

bool insertAt(List *list, DATA item, int loc){
	bool returnStatement = false;
	int i;
	if(list->count < MAX){
		if(loc != 0){
			for(i=list->count;loc = i-1; i--){
				list->elems[i] = list->elems[i-1];
			}
			list->elems[i] = item;
			list->count++;
		}else {
			for(i=list->count; i>0; i--){
				list->elems[i] = list->elems[i-1];
			}
			list->elems[loc] = item;
			list->count++;
		}
				
	}else printf("Cannot insert, storage already full!");
}

bool searchItem(List list, DATA key){
	int i; 
	bool checker = false;
	for(i=0; i<MAX && checker != true; i++){
		if(list.elems[i] == key){
			checker = true;
		}
	}
	return checker;
}

int getItem(List list, DATA key){
	bool checker = false;
	int i;
	for(i=0; i<MAX && checker != true; i++){
		if(list.elems[i] == key){
			checker = true;
		}
	}
	if (checker == true){
		return key;
	}else printf("Item does not exist");
}

bool deleteFront(List *list){
	bool checker = false;
	int i;
	if(list->count != 0){
		for(i=0; i<list->count; i++){
			list->elems[i] = list->elems[i+1];
			checker = true;
		}
		list->count--;
	}else printf("bro list is empty nothing to delete!");
	
	return checker;
}

bool deleteRear(List *list){
	bool checker = false;
	int i;
	if(list->count != 0){
		list->elems[list->count-1] = 0;
		list->count--;
	}else printf("bro list is empty already");
}

int deleteAt(List *list, int loc){
	int i;
	int receive = list->elems[loc];
	if(list->count != 0){
		if(list->elems[loc] != 0){
			for(i = loc; i < list->count-1; i++){
			list->elems[i] = list->elems[i+1];
			}
			list->count--;
		}else printf("Location already empty bruh");
	}
	return receive;
}

bool deleteItem(List *list, DATA key){
	int i;
	bool isFound = false;
	for(i=0; i<list->count && isFound != true; ++i){
		if(list->elems[i] == key){
			isFound = true;
			
		}
	}
	int j;
	for(j = i-1; j<list->count; j++){
		list->elems[j] = list->elems[j+1];
	}
	list->count--;
	
	return isFound;
}

int deleteAllItem(List *list, DATA key){
	int i, elemDeleted = 0;
	for(i=0; i<list->count; i++){
		if(list->elems[i] == key){
			list->elems[i] == 0;
			elemDeleted++;
		}
	}
	
	return elemDeleted;
}
