#include <stdio.h>
#include <math.h>

int main() {
    int x, y;

    printf("Enter integer x: ");
    scanf("%d", &x);

    printf("Enter integer y: ");
    scanf("%d", &y);
    
    printf("Function value: %.0lf\n", 
           floor((x * y + 2.0 * x - pow(y, x)) / (sin(x) + x * y - 2.0 * x + y)));
    
    return 0;
}