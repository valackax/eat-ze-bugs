#include <stdio.h>
#include <math.h>

int main() {
    int b, c;
    double a;

    printf("--- Method A (Short form of if) ---\n");
    printf("Enter integer b: ");
    scanf("%d", &b);
    printf("Enter integer c: ");
    scanf("%d", &c);

    if (c == 4 && b >= 0) {
        a = sqrt(b) + 2.0 * sqrt(c);
        printf("Result a = %.2lf\n", a);
    }
    
    if (c == 4 && b < 0) {
        printf(" Error: Cannot calculate. The root of negative number b does not exist.\n");
    }

    if (c == 0) {
        a = b / (c + 6.0); 
        printf("Result a = %.2lf\n", a);
    }

    if (c == -4) {
        a = b + 12.0 * pow(c, 3);
        printf("Result a = %.2lf\n", a);
    }

    if (c != 4 && c != 0 && c != -4) {
        printf("Error: Unable to evaluate expression. Number c is not equal to 4, 0 nor -4.\n");
    }

    return 0;
}