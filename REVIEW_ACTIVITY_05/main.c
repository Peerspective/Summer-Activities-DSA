#include <stdio.h>
#include <stdlib.h>

#include "CB.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	Student one;
	int myList = -1;
	int anotherList = -1;

	
	insertFront(&myHeap,  &myList, newStudent(1, "Jonathan", 'M', "BSIT"));
	insertFront(&myHeap,  &myList, newStudent(2, "Johanna", 'F', "BSCS"));
	insertFront(&myHeap,  &myList, newStudent(3, "John", 'M', "BSIS"));
	insertFront(&myHeap,  &myList, newStudent(4, "Johnny", 'M', "BSCS"));
	removeStudent(&myHeap, &myList, "John");
	insertFront(&myHeap,  &myList, newStudent(5, "Gran", 'M', "COM E"));
	displayList(myHeap, myList);	
	
	return 0;
}
