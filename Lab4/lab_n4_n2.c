#include <stdio.h>

int main() {
    int repeat;

    do {
        // Змінні для збереження суми для кожного з методів
        int sum_a = 0;
        int sum_b = 0; 
        int sum_c = 0;
        
        // Змінні для діапазону та дільника
        int start, end, divisor;
        int i; // Змінна для лічильника

        printf("\n--- New Calculation ---\n");
        
        // Запитуємо у користувача параметри для обчислення
        printf("Enter the start of the range (exclusive): ");
        scanf("%d", &start); // Зчитуємо початок діапазону
        
        printf("Enter the end of the range (inclusive): ");
        scanf("%d", &end);   // Зчитуємо кінець діапазону
        
        printf("Enter the divisor (e.g., 5): ");
        scanf("%d", &divisor); // Зчитуємо число, на яке шукаємо кратність

        // Захист: перевіряємо, щоб користувач випадково не ввів дільник 0
        if (divisor == 0) {
            printf("Error: Divisor cannot be zero.\n");
        } else {
            printf("\nCalculating sum of multiples of %d in range (%d; %d]\n\n", divisor, start, end);

            // Метод А: Використання циклу з for
            // Починаємо з start + 1, оскільки діапазон start означає що число не входить
            for (i = start + 1; i <= end; i++) {
                if (i % divisor == 0) {
                    sum_a += i;
                }
            }
            printf("A) Sum using 'for' loop: %d\n", sum_a);

            // Метод B: Використання циклу з while
            i = start + 1; // Скидаємо лічильник на початок діапазону
            while (i <= end) {
                if (i % divisor == 0) {
                    sum_b += i;
                }
                i++; // Збільшуємо лічильник
            }
            printf("B) Sum using 'while' loop: %d\n", sum_b);

            // Метод C: Використання циклу з (do-while
            i = start + 1; // Знову скидаємо лічильник
            
            // Додаємо if щоб уникнути помилки якщо start >= end
            // оскільки do-while завжди виконується мінімум 1 раз
            if (i <= end) {
                do {
                    if (i % divisor == 0) {
                        sum_c += i;
                    }
                    i++;
                } while (i <= end);
            }
            printf("C) Sum using 'do-while' loop: %d\n", sum_c);
        }

        printf("\nDo you want to run this again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("Exiting the program...\n");

    return 0;
}
