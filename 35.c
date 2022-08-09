/*                                                           */
/*  This is an abstract data type                            */
/*                                                           */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX_SIZE 3

struct arraycontainer  { //stores the arraystorage and the length
    int  dataarraystorage[MAX_SIZE]; //a new datatype member
    int length;
    };
typedef struct arraycontainer arraystorage; //give the structure a subject variable arraystorage
typedef arraystorage *arrayPtr;

void Menu (int *choice);
arraystorage * AddItem (arraystorage * adt, int data);
arraystorage * RemoveItem (arraystorage * adt); 
void Print (arraystorage * adt);
void Clear (arraystorage * adt);

int IsEmpty (arraystorage * adt);
arraystorage *create(arraystorage * adt);

int main () {
printf("MAX size is :%d \n",MAX_SIZE);
arraystorage * adt = create(adt); 
//create memory for adt.
    int     data, choice;
    adt->length = 0; // Set length to 0
    do {	
	Menu (&choice); //run function to make sure we have a valid integer
	switch (choice) {
	    case 1: 
		printf ("Enter data item value to add \n");
		scanf ("%d", &data);
		adt = AddItem (adt, data);
		break;
	    case 2: 
        IsEmpty(adt);
		adt = RemoveItem (adt);
		break;
	    case 3: 
		Print (adt);
		break;

	    case 4: 
		break;

	    default: 
		printf ("Invalid menu choice - try again\n");
		break;
	}
    } while (choice != 4);
    Clear (adt);
}				/* main */

void Menu (int *choice) { // Specify an universal pointer in a function without returned value 

    char    local;

    printf ("\nEnter\t1 to add item,\n\t2 to remove item\n\
\t3 to print contents\n\t4 to quit\n");
    do {
   	local = getchar ();
	if ( !( '0'< local &&  local < '5') && (local != '\n')) { //Algorithm must have an input of valid number
	    printf ("\nyou must enter an integer.\n");
	    printf ("Enter 1 to add, 2 to remove, 3 to print, 4 to quit\n");
	}
    } while (!('0'< local &&  local < '5'));
 

   *choice = (int) local - '0'; //dereference of the univeral pointer to the integer
}

arraystorage * AddItem (arraystorage * adt, int data) { 
    //Pointer AddItem to the structure defined with parameter pointer adt and int data
  //Pointer adtPts to the structure is equal to the adress of variable that pointer adt points to
	int jj = 0; // set to the length of the arraystorage
	int isDifferent = 0;
	int isFull = 0;
	int kk;

	if (adt->length == MAX_SIZE) {
				printf("ADT is already full.\n Please try again.\n");
		isFull = 1; // change isFull to 1
	}	
	for (kk = 0; kk <= adt->length; kk++) { //go through every adt entry and check whether "data" is already contained
		if (data == adt->dataarraystorage[kk]) {
			printf("Identical entries not possible! \n Please try again.");
			isDifferent = 1; // change isDifferent if is already contained
			break ;
			}
	}
if (isDifferent == 0 && isFull == 0) { // check whether data is different & and adt is not full
//currptr->dataitem = data;
		int jj = adt->length;
		adt->dataarraystorage[jj] = data;
		adt->length = jj+1;
		return adt;
    }
else {

	return adt;
    }

}
arraystorage * RemoveItem (arraystorage * adt) {
if (IsEmpty(adt) == 0) {
    int kk;
    int removed_Item;
    removed_Item = adt->dataarraystorage[0];
    printf ("Element removed is %d\n", removed_Item);
	for (kk = 0; kk < adt->length; kk++) {
	adt->dataarraystorage[kk] = adt->dataarraystorage[kk+1];
	}
	adt -> length --;
    return adt;
}
else {
	printf("Empty!");
	return adt;
}
}



void Print (arraystorage * adt) {
if (IsEmpty(adt)) {
    int kk;
	for (kk = 0; kk < adt->length; kk++) 
    printf ("%d    ",adt->dataarraystorage[kk]);
    printf("\n");
}
else printf("Empty \n");
}	


void Clear (arraystorage * adt) {
    while (adt->length != 0) {
	adt = RemoveItem (adt);
    }
}

int IsEmpty(arraystorage *adt ){
		if (adt->length == 0)		 
		    return 1;
		else return 0;
}

arraystorage * create(arraystorage * adt) {
adt   = malloc(sizeof(arraystorage));
return adt;
}
