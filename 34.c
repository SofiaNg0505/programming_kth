/*                                                           */
/*  This is an abstract data type                            */
/*                                                           */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int MAX_SIZE = 2;

struct elementStorage { //define a structure
    int     dataitem; //a new datatype member
    struct elementStorage * next; // defining next as the pointer to the structure OR creating the structure object with variable next
} ;

typedef struct elementStorage element; //give the structure a new pointer element
typedef element *elementptr;


struct dataStructure {       //header struct
	elementptr linkedList;   //Define linkedList as pointer lining struct dataDa
};
typedef struct dataStructure DataStructure;
typedef DataStructure *DataStructureptr;

void create(DataStructureptr adt) { 
adt = (DataStructure *) malloc(sizeof(DataStructure)); 
if (adt == NULL) 
printf("Out of memory!! \n\n");
}

void Menu (int *choice);
DataStructure * AddItem (DataStructure * adt, int data); //creating the strcture object Additem with parameters: pointer adt and int data 
DataStructure * RemoveItem (DataStructure * adt); 
void Print (DataStructure * adt);
void Clear (DataStructure * adt);
int IsEmpty (DataStructure * adt);

int main () {
    DataStructureptr adt; //definint new structure object adt 
    int     data, choice;

    adt->linkedList = NULL; // Set location (variable) of object to NULL 

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

DataStructure * AddItem (DataStructure * adt, int data) { 
    //Pointer AddItem to the structure defined with parameter pointer adt and int data
  //Pointer adtPts to the structure is equal to the adress of variable that pointer adt points to
 MAX_SIZE = 3;
	int i = 0;
	int isDifferent = 0;
	int isFull = 0;
	int elementCounter = 0;
	elementptr helppointer;
	elementptr currptr;
	elementptr startpointer = adt->linkedList;
//		printf("elementcounter before is: %d \n", elementCounter);
	currptr = (element *) malloc(sizeof(element));
	currptr = adt->linkedList; 
	while (currptr != NULL) { //count elements of adt
	currptr = currptr->next;
	elementCounter ++;
	}
	currptr = adt->linkedList; //reset currptr
	if (elementCounter >= MAX_SIZE) { 	//check if adt is full already
		printf("ADT is already full.\n Please try again.\n");
		isFull = 1; // change isFull to 1
	}
	while (currptr != NULL) { //go through every adt entry and check whether "data" is already contained
		if (data == currptr->dataitem) {
			printf("Identical entries not possible! \n Please try again.");
			isDifferent = 1; // change isDifferent if is already contained
			break ;
			}
		else {
		currptr = currptr->next;
		}
	}
if (isDifferent == 0 && isFull == 0) { // check whether data is different & and adt is not full
currptr = adt->linkedList;
helppointer = (element *) malloc(sizeof(element));
//currptr->dataitem = data;
helppointer = adt->linkedList;
	    if (helppointer != NULL) {
		while ( helppointer->next != NULL)  //while the value to 'next' variable of 'adt' variavle is not empty
		helppointer = helppointer->next;
		
		helppointer->next = (element *) malloc(sizeof(element));
		helppointer = helppointer->next;
		helppointer-> next = NULL;
		helppointer-> dataitem = data;
		adt->linkedList = startpointer;
		
	    //	adt->linkedList = currptr->next; //assign adt variable to next variable of adt
		//adt->linkedList->next = (element  *) malloc (sizeof (element)); // returns a pointer to the allocated memory with size of element
	//	adt->linkedList = currptr->next; //Value of adt is now the location of next of where the adt pointed to
	//	adt -> linkedList->next = NULL; //and the next variable will then be Null
	//	adt -> linkedList->dataitem = data;//stores value of data to the variable dataitem to which the pointer points
		return adt;
    }
	    else {
	adt->linkedList = (element  *) malloc (sizeof (element)); //allocate the requested memort and set it equal to the pointer adt
	adt->linkedList->next =  NULL; // Set NULL as value of the variable of next to which the adt pointer points to. 
		adt -> linkedList->dataitem = data;
	return adt;
    }
}
else {
return adt;
}
}
DataStructure * RemoveItem (DataStructure * adt) {
IsEmpty(adt);
    elementptr currptr;
    currptr = adt->linkedList;
    int removed_Item; // Pointer tempp added to the structure
    removed_Item = currptr->dataitem;
    printf ("Element removed is %d\n", removed_Item);
    adt->linkedList = currptr->next;
    free(currptr);
    return adt;
}

void Print (DataStructure * adt) {

   if (IsEmpty(adt) == 0) {
    elementptr currptr;
     	currptr = adt->linkedList;

	while (currptr != NULL) {
	    printf ("%d\t", currptr-> dataitem); //print variable(location) of the pointer 
	    currptr = currptr->next; // object adt is given 
	}
    printf ("\n");
    }
}

void Clear (DataStructure * adt) {

    while (adt->linkedList != NULL) {
	adt = RemoveItem (adt);
    }
}

int IsEmpty(DataStructure *adt ){
		if (adt->linkedList == NULL)
		  {  printf ("Empty!\n");
		  return 1;}
		  else 
		  { return 0;}

}
