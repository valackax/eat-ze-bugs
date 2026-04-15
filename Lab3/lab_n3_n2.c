#include <stdio.h>
#include <math.h>

int main() {
    double d1, d2, d3, d4;
    double product, result;

    printf("Enter the first number (d1): ");
    scanf("%lf", &d1);
    printf("Enter the second number (d2): ");
    scanf("%lf", &d2);
    printf("Enter the third number (d3): ");
    scanf("%lf", &d3);
    printf("Enter the fourth number (d4): ");
    scanf("%lf", &d4);

    if (d1 <= d2 && d2 <= d3 && d3 <= d4) {
        result = (d1 + d2 + d3 + d4) / 4.0;
        printf("\nThe numbers form a non-decreasing sequence .\n");
        printf("Arithmetic mean: %.2lf\n", result);
    } 
    else {
        printf("\nThe numbers DO NOT form a non-decreasing.\n");
        
        product = d1 * d2 * d3 * d4;
        
        if (product >= 0) {
       
            result = pow(product, 1.0 / 4.0);
            printf("Geometric mean: %.2lf\n", result);
        } else {
        printf("Error:impossible to calculate the geometric mean because the product of the numbers is negative.\n");
        }
    }

    return 0;
}