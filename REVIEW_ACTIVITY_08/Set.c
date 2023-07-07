#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

Set newSet(){
	Set A;
	int i; 
	A.count = 0 ;
	for(i=0; i<MAX; i++){
		A.elems[i] = false;
	}
	return A;
}
bool addElement(Set* s, int item){
	bool condition = false;
	
	if(s->elems[item] == 0 ){
		s->elems[item] = 1;
		s->count++;
		condition = true;
	}
	return condition;
}
bool removeElement(Set *s, int item){
	bool condition = false;
	if(s->elems[item] != 0){
		s->elems[item] = 0;
		s->count--;
		condition = true;
	}
	
	return condition;
}
void displaySet(Set s){
	int i;
	for(i=0; i<MAX; i++){
		if(s.elems[i] == 1){
			printf("%d ", i);
		}
	}
}
Set unionSet(Set a, Set b){
	Set c;
	c.count = 0;
	int i;

	
	for(i=0; i<MAX; i++){
		if((a.elems[i] | b.elems[i]) == 1){
			c.elems[i] = 1;
			c.count++;
		}else c.elems[i] = 0;
	}
	
	return c;
}
Set intersectionSet(Set a, Set b) {
	Set c;
	c.count = 0;
	int i;

	for(i=0; i<MAX; i++){
		if((a.elems[i] & b.elems[i]) == 1){
			c.elems[i] = 1;
			c.count++;
		}else c.elems[i] = 0;
	}
	
	return c;
}
Set differenceSet(Set a, Set b){
	Set c;
	c.count = 0;
	int i;

	
	for(i=0; i<MAX; i++){
		if((a.elems[i] - b.elems[i]) == 1){
			c.elems[i] = 1;
			c.count++;
		}else c.elems[i] = 0;
	}
	
	return c;
}
Set symmetricDiffSet(Set a, Set b){
	Set c,x,y;
	x = differenceSet(a,b);
	printf("Count now is %d \n", x.count);
	y = differenceSet(b,a);
	printf("Count now is %d \n", y.count);
	c = unionSet(x,y);
	printf("Count now is %d \n", c.count);
	
	return c;
	
}
int cardinality(Set s){
	return s.count;
}

