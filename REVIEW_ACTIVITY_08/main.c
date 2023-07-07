#include <stdio.h>
#include <stdlib.h>
#include "Set.h"


int main(int argc, char *argv[]) {
	Set mySet = newSet();
	Set mySet2 = newSet();
	Set setC = newSet();
	
	bool retVal;

	retVal = addElement(&mySet, 1);
	retVal = addElement(&mySet, 2);
	retVal = addElement(&mySet, 4);
	removeElement(&mySet, 0);
//	displaySet(mySet);
	
	retVal = addElement(&mySet2, 2);
	retVal = addElement(&mySet2, 6);
	retVal = addElement(&mySet2, 3);
	setC = unionSet(mySet, mySet2);
	printf("\nUnion Set: ");
	int cardinal = cardinality(setC);
	displaySet(setC);
	printf("\nCardinality of last C is : %d\n", cardinal);

	
	printf("\nIntersection Set: ");
	setC = intersectionSet(mySet, mySet2);
	cardinal = cardinality(setC);
	displaySet(setC);
	printf("\nCardinality of last C is : %d\n", cardinal);
	
	printf("\nDifference Set: ");
	setC = differenceSet(mySet, mySet2);
	cardinal = cardinality(setC);
	displaySet(setC);
	printf("\nCardinality of last C is : %d\n", cardinal);
	
	printf("\nSymmetrical Difference: ");
	setC = symmetricDiffSet(mySet, mySet2);
	cardinal = cardinality(setC);
	displaySet(setC);
	printf("\nCardinality of last C is : %d\n", cardinal);
	
	
	return 0;
}
