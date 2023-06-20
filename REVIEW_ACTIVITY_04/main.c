#include <stdio.h>
#include <stdlib.h>

#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	stack Sample;
	initStack(&Sample);
	push(&Sample, 10);
	push(&Sample, 9);
	push(&Sample, 8);
	push(&Sample, 7);
	pop(&Sample);
	peek(Sample);
	display(Sample);
	visualize(Sample);
	
	return 0;
}
