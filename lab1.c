//Xinyan Liu
//CS 5008 Lab1 Student project
//Jan 19,2023

#include <stdio.h>
//function declaration
void getlastName(char *lastname);
int getStudentAge(int *age);
float getStudentGPA(float *gpa);
float getExamscore(float *finalExamScore);
void getLetterGrade(float *finalExamScore);
void printData(char *lastname,int *age,float *gpa,float *finalExamScore);

//function defination:
void getlastName(char *lastname){
    printf("print out student last name is:%s \n",lastname);
}

int getStudentAge(int *age){
    return *age;
}

float getStudentGPA(float *gpa){
    return *gpa;
}

float getExamscore(float *finalExamScore){
    return *finalExamScore;
}

void getLetterGrade(float *finalExamScore){
    if (*finalExamScore >= 90){ 
        printf("Grade is A \n");
    }else if (*finalExamScore >= 85) 
    {   
        printf("Grade is B \n");
    }else if (*finalExamScore >= 80){    
        printf("Grade is C \n");
    }else if (*finalExamScore >= 75){       
        printf("Grade is D \n");
    }
    else if (*finalExamScore < 75){      
        printf("Grade is S \n");
    }
}

void printData(char *lastname,int *age,float *gpa,float *finalExamScore){
    printf("last name is %s, student age is %i, student gpa is %f,exam score is %f",lastname,*age,*gpa,*finalExamScore);
    
}


//task 1 complete a main function
//allow user to enter the data via standard input and output the data via a standard output
int main(void){
    //checkpint 1
    char lastName[10];
    printf("Enter your last name: \n");
    scanf("%s", lastName); 

    int age;
    printf("Enter your age: \n");
    scanf("%i", &age);
    
    float gpa;
    printf("Enter your GPA: \n");
    scanf("%f", &gpa);
    
    float finalExamScore;
    printf("Enter your final exam score: \n");
    scanf("%f", &finalExamScore);

    char Grade;
    if (finalExamScore >= 90){ 
        Grade = 'A';
        printf("Grade is A \n");
    }else if (finalExamScore >= 85) 
    {   Grade = 'B';
        printf("Grade is B \n");
    }else if (finalExamScore >= 80){
        Grade = 'C';   
        printf("Grade is C \n");
    }else if (finalExamScore >= 75){
        Grade = 'D';      
        printf("Grade is D \n");
    }
    else if (finalExamScore < 75){ 
        Grade = 'S';      
        printf("Grade is S \n");
    }
   
   //task 2 output the addresses of the variables uses:
   //how many bytes are used to store the variables 
   //checkpint 2
   printf("The size of student last name is %lu and it is stored in %p \n ", sizeof lastName,&lastName);
   printf("The size of student age is %lu and it is stored in %p \n ", sizeof age,&age);
   printf("The size of student gpa is %lu and it is stored in %p \n ", sizeof gpa,&gpa);
   printf("The size of student final exam is %lu and it is stored in %p \n ", sizeof finalExamScore,&finalExamScore);
   printf("The size of student final exam score is %lu and it is stored in %p \n ", sizeof Grade,&Grade);

    //task 3 output the data using a function
    //checkpint 3
    //function call:
    
    int getage;
    float getgpa;
    float getGrade;

    getlastName(lastName);
    getage=getStudentAge(&age);
    getgpa=getStudentGPA(&gpa);
    getGrade=getExamscore(&finalExamScore); 
    
    printf("print out student age is:%i \n",getage);
    printf("print out student gpa is:%f \n",getgpa);
    printf("print out student exam score is:%f \n",getGrade);

    //task 4 create a function that receives a student exam score and determines what their letter grade is
    //checkpint 4
    //Letter Grade Function recieves a student exam score and determines what their letter grade is
    getLetterGrade(&finalExamScore);

    //print data function output last name,student age,student gpa,exam score onto the standard output
    printData(lastName,&age,&gpa,&finalExamScore);

}






