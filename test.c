#include <stdio.h>

/* Your solution goes here  */
// float MphAndMinutesToMiles(float milesPerHour, float minutesTraveled);

// float MphAndMinutesToMiles(float milesPerHour, float minutesTraveled){
//    double hoursTraveled;
//    double milesTraveled;
   
//    hoursTraveled = minutesTraveled / 60.0;
//    milesTraveled = hoursTraveled * milesPerHour;
   
//    return milesTraveled;
//    }
   

// int main(void) {
//    double milesPerHour;
//    double minutesTraveled;

//    scanf("%lf", &milesPerHour);
//    scanf("%lf", &minutesTraveled);

//    printf("Miles: %lf\n", MphAndMinutesToMiles(milesPerHour, minutesTraveled));

//    return 0;
// }


// int Compute(int val1, int val2) {
//    int result = 0;
//    int i;

//    for (i = 0; i < val1; ++i) {
//       result -= val2 * 3;
//    }
   
//    return result;
// }

// int main(void) {
//    int value1 = 3;
//    int value2 = 2;
//    int computedValue;

//    computedValue = Compute(value1, value2);
//    printf("%d\n", computedValue);
   
//    return 0;
// }




#include <stdio.h>

void PrintSelectedNumbers(int numCount) {
   int i;
   int number;

   for (i = 0; i < numCount; ++i) {
      scanf("%d", &number);
      if ((number % 3) != 0) {
         printf("%d\n", number);
      }
   }
}

int main(void) {
   int numCount = 5;

   PrintSelectedNumbers(numCount);

   return 0;
}