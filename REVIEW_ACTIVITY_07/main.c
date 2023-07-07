#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackQueueCB.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualSpace B = newVirtualSpace();
	Queue q;
	Product p = createProduct(1, "Vaseline", 1, 123.00, createDate(1,23,23));
	initQueue(&q);
	
	enqueue(&B, &q, p);
	
	visualizeVspace(B);
	
	return 0;
}
