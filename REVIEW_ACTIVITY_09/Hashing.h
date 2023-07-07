#ifndef HASHING_H
#define HASHING_H

#include <stdbool.h>
#define MAX 20
typedef char String[20];
typedef struct {
	String Fname;
	String Lname;
	char middle;
}Name;

typedef struct{
	int date;
	int month;
	int year;
}Date;

typedef struct {
	int studID;
	Name studName;
	bool sex;
	Date birthdate;
	String program;
	int year;
}Student;

typedef struct node {
	Student S;
	int *next;
}SType;

typedef struct {
	SType *T;
	int count;
	int max;
}Dictionary;


void initDictionary(Dictionary *d, int size); // initialize max as 26;
int Hashing(Student s, int size);
bool addElement(Dictionary *d, Student s);
Student deleteElement(Dictionary *d, Student s);
bool searchElement(Dictionary d, Student s);
bool editElement(Dictionary *d, Student s);
void visualizeDictionary(Dictionary d);
#endif
