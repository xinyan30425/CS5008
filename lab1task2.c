#include <stdio.h>

//create functions that get the required data item.
void getlastName(char* lastname){
    char lastname[10];
    printf("Student last name is",lastname);
    
}

int getStudentAge(){
    int age;
    printf("Enter your age: \n");
    scanf("%i", &age);
    return age;
}

float getStudentGPA(){
    float gpa;
    printf("Enter your GPA: \n");
    scanf("%f", &gpa);
    return gpa;
}

float getStudentGrade(){
    float finalExamScore;
    printf("Enter your final exam score: \n");
    scanf("%f", &finalExamScore);
    return finalExamScore;
}

int main(void){
    char lastname = getlastName(lastname);
    int age = getStudentAge();
    float gpa = getStudentGPA();
    float finalExamScore = getStudentFinalExamScore();
    char Grade = getStudentGrade();



}


char getlastName(lastname){
    char lastname[10];
    printf("Enter your last name: \n");
    scanf("%s", lastname); 
    printf("Student last name is %s",lastname);
    
}