#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"

void DinitList(List *list){
	list->count = 0;
	int i;
	
	for(i=0; i<list->max; i++){
		list->elems[i] = 0;
	}
}

List DnewList(int max){
	List A;
	DATA* temp;
	int i;
	A.max = max;
	
	temp = (DATA*)malloc(max * sizeof(DATA));
	
	if (temp == NULL) {
		
		printf("Memory not allocated");
		
	}
	
	for(i=0; i<A.max; i++){
		A.elems[i] = temp[i];
	}
	
	DinitList(&A);
	
	return A;
}

void DdisplayList(List list){
	int i;
	
	for(i=0; i<list.max; i++){
		printf("%d ", list.elems[i]);
	}
}

bool DinsertFront(List *list, DATA item){
	bool returnStatement = false;
	int i;
	if(list->count<list->max){
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

bool DinsertRear(List *list, DATA item){
	bool returnStatement = false;
	if(list->count < list->max){
		list->elems[list->count] = item;
		list->count++;
		returnStatement = true;
	}else printf("Cannot insert, storage already full!");
	
	return returnStatement;
}

bool DinsertSorted(List *list, DATA item){
	bool returnStatement = false;
	int i;
	if(list->count < list->max){
		if(list->count != 0){
			for(i=list->count; list->elems[i-1] > item; i--){ //efficient?
				list->elems[i] = list->elems[i-1];
			}
			list->elems[i] = item;
			list->count++;
		}else list->elems[0] = item;
	}else printf("Cannot insert, storage already full!");
}

bool DinsertAt(List *list, DATA item, int loc){
	bool returnStatement = false;
	int i;
	if(list->count < list->max){
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

bool DsearchItem(List list, DATA key){
	int i; 
	bool checker = false;
	for(i=0; i<list.max && checker != true; i++){
		if(list.elems[i] == key){
			checker = true;
		}
	}
	return checker;
}

int DgetItem(List list, DATA key){
	bool checker = false;
	int i;
	for(i=0; i<list.max && checker != true; i++){
		if(list.elems[i] == key){
			checker = true;
		}
	}
	if (checker == true){
		return key;
	}else printf("Item does not exist");
}

bool DdeleteFront(List *list){
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

bool DdeleteRear(List *list){
	bool checker = false;
	int i;
	if(list->count != 0){
		list->elems[list->count-1] = 0;
		list->count--;
	}else printf("bro list is empty already");
}

int DdeleteAt(List *list, int loc){
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

bool DdeleteItem(List *list, DATA key){
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

int DdeleteAllItem(List *list, DATA key){
	int i, elemDeleted = 0;
	for(i=0; i<list->count; i++){
		if(list->elems[i] == key){
			list->elems[i] == 0;
			elemDeleted++;
		}
	}
	
	return elemDeleted;
}
