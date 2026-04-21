#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int repeat;

    do {
        int n, i, mode;
        int a[100];
        
        int sum_abs_neg = 0;   
        int last_neg_idx = -1; // -1 означає що від'ємних елементів ще не знайдено
        long long prod = 1;    // Добуток починаємо з 1, а не з 0

        printf("\n--- Array Processing ---\n");

        // Введення розміру масиву із захистом від помилок (область допустимих значень)
        do {
            printf("Enter array size n (1-100): ");
            scanf("%d", &n);
        } while (n <= 0 || n > 100);

        // Вибір способу заповнення масиву: вручну чи випадково
        do {
            printf("Choose input method (1 - Keyboard, 2 - Random [-100; 100]): ");
            scanf("%d", &mode);
        } while (mode != 1 && mode != 2);

        // Заповнення масиву залежно від обраного режиму
        if (mode == 1) {
            printf("Enter %d integer elements:\n", n);
            for (i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }
        } else {
            srand(time(0)); // Ініціалізація генератора випадкових чисел від поточного часу
            printf("Generated array:\n");
            for (i = 0; i < n; i++) {
                // Формула для генерації чисел у діапазоні [-100; 100]
                a[i] = -100 + rand() % 201;
                printf("%d  ", a[i]);
            }
            printf("\n");
        }

        // Проходимо по масиву для пошуку від'ємних елементів
        for (i = 0; i < n; i++) {
            if (a[i] < 0) {
                sum_abs_neg += abs(a[i]); // Додаємо модуль від'ємного числа до суми
                last_neg_idx = i;         // Постійно оновлюємо індекс останнього знайденого
            }
        }

        // Вивід першого результату (сума модулів)
        printf("\n1) Sum of absolute values of negative elements: %d\n", sum_abs_neg);

        // Обчислення добутку елементів ДО останнього від'ємного
        if (last_neg_idx > 0) {
            // Якщо останній від'ємний не на нульовій позиції рахуємо добуток
            for (i = 0; i < last_neg_idx; i++) {
                prod *= a[i];
            }
            printf("2) Product of elements before the last negative element (index %d): %lld\n", last_neg_idx, prod);
            
        } else if (last_neg_idx == 0) {
            // Якщо останній від'ємний елемент стоїть найпершим то перед ним немає чисел
            printf("2) The last negative element is at index 0. There are no elements before it to calculate the product.\n");
            
        } else {
            // Якщо last_neg_idx так і залишився -1
            printf("2) There are no negative elements in the array.\n");
        }

        printf("\nDo you want to run the program again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("Exiting the program...\n");

    return 0;
}