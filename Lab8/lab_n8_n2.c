#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Функція для ініціалізації масиву випадковими числами [-100; 100]
// Використовуємо вказівник *arr для доступу до пам'яті
void init_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        // Звертання до елемента через вказівникову арифметику
        *(arr + i) = -100 + rand() % 201; 
    }
}

// 2. Функція для виведення масиву на екран
void print_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// 3. Функція для знаходження максимального елемента масиву
int find_max(int *arr, int n) {
    int max_val = *arr; // Беремо перший елемент як початковий максимум
    int i;
    
    for (i = 1; i < n; i++) {
        if (*(arr + i) > max_val) {
            max_val = *(arr + i);
        }
    }
    return max_val;
}

// 4. Функція для обчислення добутку між першим та останнім від'ємним елементами
// Використовуємо вказівник *is_valid, щоб повідомити main(), чи обчислення взагалі можливе
long long calc_product_between_negatives(int *arr, int n, int *is_valid) {
    int first_neg = -1;
    int last_neg = -1;
    int i;
    long long prod = 1;

    // Шукаємо індекси першого та останнього від'ємного елемента
    for (i = 0; i < n; i++) {
        if (*(arr + i) < 0) {
            if (first_neg == -1) {
                first_neg = i; // Запам'ятовуємо перший знайдений
            }
            last_neg = i; // Постійно оновлюємо для пошуку останнього
        }
    }

    // Перевірка, чи коректно розташовані від'ємні елементи
    if (first_neg == -1 || first_neg == last_neg || (last_neg - first_neg) == 1) {
        *is_valid = 0; // Змінюємо значення за адресою: обчислення неможливе
        return 0;
    }

    *is_valid = 1; // Обчислення можливе
    
    // Рахуємо добуток елементів строго між ними
    for (i = first_neg + 1; i < last_neg; i++) {
        prod *= *(arr + i);
    }
    
    return prod;
}

int main() {
    int repeat;
    
    // Ініціалізація генератора випадкових чисел від поточного часу
    srand(time(0)); 
    
    // Головний зовнішній цикл програми
    do {
        const int MAX_SIZE = 100;
        int a[100];
        int n;
        
        printf("\n--- Array Processing ---\n");
        
        // Перевірка ОДЗ при введенні розміру
        do {
            printf("Enter the number of array elements (1 to %d): ", MAX_SIZE);
            scanf("%d", &n);
            if (n <= 0 || n > MAX_SIZE) {
                printf("Error: Invalid array size.\n");
            }
        } while (n <= 0 || n > MAX_SIZE);
        
        // У головній програмі виконуються виключно виклики функцій
        init_array(a, n);
        
        printf("Generated array:\n");
        print_array(a, n);
        
        // Завдання 1: Знаходження максимального елемента
        int max_element = find_max(a, n);
        printf("\n1) The maximum element of the array is: %d\n", max_element);
        
        // Завдання 2: Добуток між від'ємними
        int is_valid;
        long long product = calc_product_between_negatives(a, n, &is_valid); // Передаємо адресу &is_valid
        
        if (is_valid == 1) {
            printf("2) The product of elements between the first and last negative elements is: %lld\n", product);
        } else {
            printf("2) Cannot calculate the product. Not enough negative elements, or no elements between them.\n");
        }

        printf("\nDo you want to run the program again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);
        
    } while (repeat == 1);
    
    printf("Exiting the program...\n");
    return 0;
}