#include <stdio.h>
#include <math.h>

int main() {
    const double a = 25.0;
    const double b = -2.0;
    const double c = 4.0;

    printf("Function value y = %lf\n", (a * b * c + a * b - (2.0 * a + c)) / (2.0 * a * (b - c)) - a / 5.0);

    return 0;
}