#include <stdio.h>
#include <math.h>

int main() {
    int repeat;

    do {
        // Оголошуємо Пі як звичайну константу
        const double PI = 3.141592653589793;
        
        // Ініціалізуємо змінні
        double a = 0.0;
        double b = PI;
        double dx = PI / 20.0;
        double x, y, radicand;

        printf("\n--- Function Tabulation ---\n");
        
        // Виведення шапки таблиці 
        printf("---------------------------------\n");
        printf("|      X      |     Y = f(X)    |\n");
        printf("---------------------------------\n");

        x = a;

        // Цикл для проходження інтервалу. Додаємо 1e-5 для компенсації похибки дійсних чисел
        while (x <= b + 1e-5) {
            
            // 1-ша виключна ситуація: тангенс не існує при x = Пі/2
            // Використовуємо fabs() для безпечного порівняння дійсних чисел
            if (fabs(x - PI / 2.0) < 1e-5) {
                printf("| %10.4lf | Undefined (tan) |\n", x);
            } else {
                // Знаходимо підкореневий вираз
                radicand = tan(x) + 13.0;
                
                // 2-га виключна ситуація: підкореневий вираз парного степеня не може бути від'ємним
                if (radicand < 0) {
                    printf("| %10.4lf | Negative root   |\n", x);
                } else {
                    // Обчислюємо корінь 4-го степеня (піднесення до степеня 0.25)
                    y = pow(radicand, 0.25);
                    
                    // Виводимо обчислене значення
                    printf("| %10.4lf | %15.4lf |\n", x, y);
                }
            }
            
            // Переходимо до наступного значення X
            x += dx;
        }

        printf("---------------------------------\n");

        printf("\nDo you want to run the tabulation again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1); 

    printf("Exiting the program...\n");

    return 0;
}
