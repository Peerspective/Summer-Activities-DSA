#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CB.h"


Student newStudent(int studID, String studName, char sex, String program){
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);
	
	return s;
}
VirtualHeap newVirtualHeap(){
	VirtualHeap vh;
	int i;
	
	for(i = 0; i<MAX; ++i){
		vh.elems[i].elem = newStudent(0," ",' ', " ");
		vh.elems[i].next = i-1;
	}
	vh.avail = MAX-1;
	
	return vh;
}
int allocSpace(VirtualHeap *vh){
	int retVal = vh->avail;
	
		if(retVal != -1){
			vh->avail = vh->elems[vh->avail].next;
		}
		
	return retVal;
}
void insertFront(VirtualHeap *vh, int *list, Student s) {
	int temp = allocSpace(vh); //get the location that is free
	
	if(temp != -1){
		vh->elems[temp].next = *list;
		*list = temp;
		
		vh->elems[temp].elem = s;
	}
}

void displayList(VirtualHeap vh, int list){
	int i;
	
	printf("%5s | %-30s | %s\n", "INDEX", "ELEMS", "NEXT");
	printf("---------------------------------------------\n");
	
	for(i=list; i != -1; i = vh.elems[i].next){
		printf("%5d | ", i);
		printf("%4d -  %23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		printf("%d\n", vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vh.avail);
}

void visualizeSpace(VirtualHeap vh){
	int i;
	printf("%5s | %-30s | %s\n", "INDEX", "ELEMS", "NEXT");
	printf("---------------------------------------------\n");
	
	for(i = 0; i< MAX; ++i){
		printf("%5d | ", i);
		if(vh.elems[i].elem.studID == 0) {
			printf("%30s | ", "Empty");
		} else {
			printf("%4d -  %23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		}
		printf("%d\n", vh.elems[i].next);
	}
	
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vh.avail);
}

void deallocSpace(VirtualHeap *vh, int index){
	if(index != -1 && index < MAX){
		vh->elems[index].next = vh->avail;
		vh->elems[index].elem = newStudent(0," ",' ', " ");
		vh->avail = index;
	}
}

Student removeStudent(VirtualHeap *vh, int *list, String keyword){
	int i = *list;
	while(i != -1){
		if(strcmp(vh->elems[i].elem.studName, keyword) == 0){
			vh->elems[i-1].next = vh->elems[i].next;
			vh->elems[i].next = vh->avail;
			vh->avail = i;
		}
		i = vh->elems[i].next;
	}
	
	deallocSpace(vh, i);
}
