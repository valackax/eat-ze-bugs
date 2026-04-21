#include <stdio.h>

int main() {
    int repeat;

    do {
        // Оголошення констант та масивів
        const int MAX_SIZE = 100; 
        
        double a[100];
        double c[100];
        int n, i;

        // Обов'язково обнуляємо ці змінні на початку кожного нового циклу
        int is_alternating = 1; // Прапорець: 1 true - знаки чергуються, 0 - ні
        int c_count = 0;        // Лічильник елементів для нового масиву

        printf("\n--- New Array Processing ---\n");

        // Цикл для перевірки коректності введеного розміру масиву
        do {
            printf("Enter the number of elements (1 to 100): ");
            scanf("%d", &n);
            
            // Використовуємо нашу константу MAX_SIZE для перевірки
            if (n <= 0 || n > MAX_SIZE) {
                printf("Error: Invalid array size.\n");
            }
        } while (n <= 0 || n > MAX_SIZE);

        // Введення елементів початкового масиву з клавіатури
        printf("Enter %d real numbers:\n", n);
        for (i = 0; i < n; i++) {
            printf("a[%d] = ", i);
            scanf("%lf", &a[i]);
        }

        // Перевірка чи чергуються додатні та від'ємні елементи
        if (n >= 2) {
            for (i = 0; i < n - 1; i++) {
                // Якщо два сусідні елементи мають однаковий знак або один з них нуль
                if ((a[i] > 0 && a[i+1] > 0) || 
                    (a[i] < 0 && a[i+1] < 0) || 
                    (a[i] == 0) || (a[i+1] == 0)) {
                    is_alternating = 0; // Чергування порушено
                    break; // Зупиняємо перевірку для економії ресурсів
                }
            }
        }

        // Виведення результату залежно від того чи було чергування
        if (is_alternating) {
            printf("\nThe elements alternate. Original array:\n");
            for (i = 0; i < n; i++) {
                printf("%.2lf  ", a[i]);
            }
            printf("\n");
        } else {
            printf("\nThe elements do not alternate. Creating new array c[i]...\n");
            
            // Формування нового масиву лише з від'ємних елементів
            for (i = 0; i < n; i++) {
                if (a[i] < 0) {
                    c[c_count] = a[i];
                    c_count++; // Збільшуємо лічильник для наступного від'ємного елемента
                }
            }

            // Перевірка чи були знайдені від'ємні елементи
            if (c_count == 0) {
                printf("No negative elements were found in the initial array.\n");
            } else {
                printf("New array c (only negative elements):\n");
                for (i = 0; i < c_count; i++) {
                    printf("%.2lf  ", c[i]);
                }
                printf("\n");
            }
        }

        printf("\nDo you want to process another array? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("Exiting the program...\n");

    return 0;