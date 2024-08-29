#include <stdio.h>

int main(void){
    char lastName[10];
    printf("Enter your last name: \n");
    scanf("%s", lastName); 

    int age;
    printf("Enter your age: \n");
    scanf("%i", &age);
    
    float gpa;
    printf("Enter your GPA: \n");
    scanf("%f", &gpa);
    
    float finalExam;
    printf("Enter your final exam score: \n");
    scanf("%f", &finalExam);

    char finalExamScore;
    if (finalExam >= 90){ 
        printf("Grade is A \n");
    }else if (finalExam >= 85) 
    { 
        printf("Grade is B \n");
    }else if (finalExam >= 80){   
        printf("Grade is C \n");
    }else if (finalExam >= 75){      
        printf("Grade is D \n");
    }
    else if (finalExam < 75){       
        printf("Grade is S \n");
    }
    return 0;
}