#include <stdio.h>
#include <math.h>

// Визначення функції для пошуку більшого з двох дійсних чисел
// Тип результату - double, оскільки ми працюємо з дійсними числами
double get_max(double x, double y) {
    if (x > y) {
        return x; // Повертає x, якщо воно більше
    } else {
        return y; // Повертає y в іншому випадку
    }
}

int main() {
    int repeat; // Змінна для керування головним циклом

    // Головний зовнішній цикл для багаторазового виконання програми
    do {
        double a, b, c, u;
        double max1, max2, max3;
        double denominator;

        printf("\n--- Expression Calculation ---\n");

        // Введення дійсних чисел a, b, c з клавіатури
        printf("Enter real number a: ");
        scanf("%lf", &a);
        
        printf("Enter real number b: ");
        scanf("%lf", &b);
        
        printf("Enter real number c: ");
        scanf("%lf", &c);

        // Виклик нашої функції get_max для обчислення чисельника
        max1 = get_max(a, a + b);
        max2 = get_max(a, b + c);
        
        // Виклик get_max для обчислення знаменника (a + bc означає a + b * c)
        max3 = get_max(a + b * c, b - c); 

        // Загальний знаменник
        denominator = 1.0 + max3;

        // Перевірка ОДЗ: знаменник не може дорівнювати нулю
        // Використовуємо fabs() для безпечного порівняння дійсних чисел з нулем
        if (fabs(denominator) < 1e-6) {
            printf("Error: Division by zero is not allowed. Please enter different values.\n");
        } else {
            // Обчислення кінцевого результату u
            u = (max1 + max2) / denominator;
            
            // Виведення результату з точністю до 4 знаків після коми
            printf("Calculated result u = %.4lf\n", u);
        }

        printf("\nDo you want to calculate again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("Exiting the program...\n");

    return 0;
}