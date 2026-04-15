#include <stdio.h>
#include <math.h>

int main() {
    int b, c;
    double a;

    printf("--- Method B (Full form of if...else if) ---\n");
    printf("Enter integer b: ");
    scanf("%d", &b);
    printf("Enter integer c: ");
    scanf("%d", &c);

    if (c == 4) {
        if (b >= 0) {
            a = sqrt(b) + 2.0 * sqrt(c);
            printf("Result a = %.2lf\n", a);
        } else {
            printf(" Error: Cannot calculate. The root of negative number b does not exist.\n");
        }
    } 
    else if (c == 0) {
        a = b / (c + 6.0);
        printf("Result a = %.2lf\n", a);
    } 
    else if (c == -4) {
        a = b + 12.0 * pow(c, 3);
        printf("Result a = %.2lf\n", a);
    } 
    else {
        printf(" Error: Unable to evaluate expression. Number c is not equal to 4, 0 nor -4.\n");
    }

    return 0;
}