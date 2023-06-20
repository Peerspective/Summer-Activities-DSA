#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char *argv[]) {
	List B = newList();
	bool retVal;
	
	insertFront(&B, 10);
	insertFront(&B, 9);
	
	displayList(B);
	
	return 0;
}
