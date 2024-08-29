
#include <stdio.h> //pre-processor directives


//RLWM Right Left Walk Method

int main (void){
 printf("Hello World \n");

 char character;
 character ="A"

 int daysInAYear;
 daysInAYear = 365;

 float heightInCm;
 heightInCm = 102.5;

 _Bool boolean;
 boolean = True;

 printf(character,"\n");
 printf(boolean, "\n");
 printf(daysInAYear,"\n");
 printf(heightInCm,"\n");


 return 0;
}

//xcode-select --install

#include <stdio.h>
 
int main()
{
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");
 
    return 0;
}

int main() {
    //declare x as an integer and initialize it to 5
    int x = 5;
    printf("first x: %d\n", x);

    { //new scope
    //declare x as a new integer inside this scope and initialize it to 10
    int x=10;
    printf("second x: %d\n", x);
    }

    //go back to the first x
    printf("third x: %d\n", x);

    //assign a new value to x
    x = 7;
    printf("fourth x: %d\n", x);

    return 0;



}


