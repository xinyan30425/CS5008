#include "studentvector_ood.h"

//known type
typedef struct student STUDENT;//forward declaration

struct student{
	
	int Capacity; //how much data we can keep
	int total; //no of items at a single point in time inside the array
	int * studentData; //will hold adress of the array.

};

//returns an opaque object
//allocates memory for a new instance of the student struct, initialize its fields
//return an opaque pointer to the new struct
MY_STUDENT allocate(void){
	//consider grades as integers - not always true- for static array
	STUDENT * studentGrades = (STUDENT *)malloc(sizeof(STUDENT));
	if (studentGrades == NULL){
		printf("No memory \n");
		exit(-1);
	}
	studentGrades->Capacity = 7;
	studentGrades->total=0;
	//allocate memory for array
	studentGrades->studentData = (int *) calloc (sizeof(int), studentGrades->Capacity);
	//TEST if calloc did allocate memory
	if (studentGrades->studentData == NULL){
		return 0;
	}	
	//typecast to opaque	
	return (MY_STUDENT) studentGrades;

}
//function definition
//print the current contents of the vector 
void printGrades(MY_STUDENT pStudentGrades){
	//takes an apaque pointer to a student struct and prints the values in the array of student grades
	STUDENT * sGrades = (STUDENT *) pStudentGrades;//dereferencing 
	int i = 0;
	while (i<sGrades->total){
		printf("%d \n",sGrades->studentData[i]);
		i++;
	}

return;
}

//check whether the vector is full
//takes an opaque pointer to a student struct and checks whether the number of items in the vector is less than the capacity of the vector
STATUS isFull(MY_STUDENT pStudentGrades) {

	STUDENT * pStudent = (STUDENT *) pStudentGrades;
	
    if (pStudent->total<pStudent->Capacity){
        return FALSE; 
      }

   return TRUE;  
}

//function that pushes or inserts an item in the array
//an integer represents a new student grade and add the grade to the vector

OUTCOME push(MY_STUDENT * pStudentGrades,int item){
	//takes an apaque pointer to a student strcut
	STUDENT * sGrades = (STUDENT *) *pStudentGrades;//dereferencing 

	int * temp = NULL;
	
	if (isFull(sGrades)){
		//array is full, how do we increase array size?
		temp = (int *) calloc (sizeof(int), sGrades->Capacity * 2);
		//check whether increase size worked.
		if(temp == NULL){
			return FAILURE;
		}
		//copy items from old array into array
		for (int i = 0; i <sGrades->Capacity; i++){
			temp[i] = sGrades->studentData[i];
		}
		//deallocate memory from old array
		free(sGrades->studentData);
		
		//point old pointer to new pointer
		sGrades->studentData = temp;
		
		//double capacity
		sGrades->Capacity = sGrades->Capacity * 2;
	}
	
	sGrades->studentData[sGrades->total] = item;
	sGrades->total++;

 //return SUCCESS if the operation was successful
 return SUCCESS;
}

//Your code for deepCopy goes in here:
//extend the vector abstract data type
MY_STUDENT deepCopy(MY_STUDENT * currentStudent){
	//Cast an opaque pointer to student struct
	STUDENT *sGrades = (STUDENT*)* currentStudent;
	//allocate memory for new student struct
	STUDENT *newStudentGrades =(STUDENT*)malloc(sizeof(STUDENT));
	//check if memory was allocated
	if (newStudentGrades == NULL){
		printf("No memory \n");
		exit(-1);
	}

	//copy over capacity and total values
	newStudentGrades->Capacity = sGrades->Capacity;
	newStudentGrades->total=sGrades->total;

	//allocate memory for array
	newStudentGrades->studentData=(int*)calloc(newStudentGrades->Capacity,sizeof(int));
	if (newStudentGrades->studentData ==NULL){
		printf("No memory \n");
		exit(-1);
	}

	//copy array values
	for (int i=0;i<sGrades->total;i++){
		newStudentGrades->studentData[i]=sGrades->studentData[i];	
	}
	//cast new student struct to opaque pointer and return
	return (MY_STUDENT)newStudentGrades;
}

//deallocate the memory for the student struct, and set the opaque pointer to NULL
void deallocate(MY_STUDENT * pStudentGrades){
	//takes a pointer to an opaque pointer to a student struct
	STUDENT * sGrades = (STUDENT *) *pStudentGrades;//dereferencing 
	
	if (*pStudentGrades != NULL){
		free(sGrades->studentData);
		free(sGrades);
	}
	*pStudentGrades = NULL;
	
	return;
}

