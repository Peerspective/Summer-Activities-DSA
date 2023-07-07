#include <stdio.h>
#include <stdlib.h>

#include "Hashing.h"

void initDictionary(Dictionary *d, int size){ // initialize max as 26; 
	
	d->max = size;
	d->count = 0;
	
	d->T = malloc(sizeof(Student) * d->max);
	int i;
	
	for(i=0;i<d->max; i++){
		d->T[i].next = NULL;
	}
	
	
}
int Hashing(Student s, int size){ // size here is the size of Dictionary
	int lastname = s.studName.Lname[0];
	
	return lastname%size;
}
bool addElement(Dictionary *d, Student s);
Student deleteElement(Dictionary *d, Student s);
bool searchElement(Dictionary d, Student s);
bool editElement(Dictionary *d, Student s);
void visualizeDictionary(Dictionary d);
