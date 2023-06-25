#include <stdio.h>
#include <stdlib.h>

#include "circularQ.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Queue myQ;
	int choice;
	String menuOption[7] = {"Enqueue", "Dequeue", 
					 "isEmpty", "isFull", "Display", "Visualize",
					 "Front"};
	int i, value, f;
	bool retVal;
	initQueue(&myQ);
	
	do {
		system("cls");
		printf("MENU\n");
		for(i = 0; i < 7; ++i){
			printf("[%d] %s\n", i+1, menuOption[i]);
		}
		printf("Enter your choice <0 to EXIT>: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
					printf("Enqueue\n");
					printf("enter a number: ");
					scanf("%d", &value);
					enqueue(&myQ, value);
					visualize(myQ);
					break;
			case 2:
					printf("Dequeue\n");
					dequeue(&myQ);
					break;
			case 3:
					retVal = isEmpty(myQ);
					printf("isEmpty == %d\n", retVal);
					break;
			case 4:
					retVal = isFull(myQ);
					printf("isFull == %d\n", retVal);
					break;
			case 5:
					printf("Display\n");
					display(myQ);
					break;
			case 6:
					printf("Visualize\n");
					visualize(myQ);
					break;
			case 7:
					f = front(myQ);
					printf("%d", f);
					break;
			case 0:
					printf("Thank You!\n");
					break;
			default:
				printf("Invalid choice...\n");
		}
		system("pause");
	} while (choice != 0);
	printf("Bye!!\n");
	
	return 0;
}
