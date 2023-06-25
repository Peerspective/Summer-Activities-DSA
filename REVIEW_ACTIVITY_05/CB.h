#ifndef CURSOR_BASE_H
#define CURSOR_BASE_H

#define MAX 10
typedef char String[20];

typedef struct {
	int studID;
	String studName;
	char sex;
	String program;
} Student;

typedef struct {
	Student elem;
	int next;
} Stype;

typedef struct {
	Stype elems[MAX];
	int avail;
} VirtualHeap;

Student newStudent(int studID, String studName, char sex, String program);
VirtualHeap newVirtualHeap();
int allocSpace(VirtualHeap *vh);
void insertFront(VirtualHeap *vh, int *list, Student s);
 
void displayList(VirtualHeap vh, int list);
void visualizeSpace(VirtualHeap vh);

void deallocSpace(VirtualHeap *vh, int index);
Student removeStudent(VirtualHeap *vh, int *list, String keyword);

#endif
