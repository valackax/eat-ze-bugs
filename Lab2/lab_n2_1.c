#include <stdio.h>
#include <math.h>

int main(){
    int num1, num2;
  
    printf("Enter first integer:");
    scanf("%d", &num1);
  
    printf("Enter second integer:");
    scanf("%d", &num2);
  
    printf("Remainder of dividing the 1st number by the 2nd: %d\n", num1 % num2);
    
    printf("The integer part of dividing the 2nd number by the 1st: %d\n", num2 / num1);
    
    printf("Triple the sum of the given numbers: %d\n", 3 * (num1 + num2));
    
    return 0;
}