#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // Підключаємо для використання функції abs()

// 1. Функція для ініціалізації масиву випадковими числами [-100; 100]
// Згідно теорії, масив передається у функцію просто вказавши пусті дужки []
void init_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = -100 + rand() % 201;
    }
}

// 2. Функція для виведення масиву на екран
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 3. Функція для знаходження мінімального за модулем елемента
// Повертає значення знайденого елемента
int find_min_abs(int arr[], int n) {
    int min_elem = arr[0];
    int min_abs = abs(arr[0]);
    int i;
    
    for (i = 1; i < n; i++) {
        if (abs(arr[i]) < min_abs) {
            min_abs = abs(arr[i]);
            min_elem = arr[i]; // Зберігаємо саме число, а не його модуль
        }
    }
    return min_elem;
}

// 4. Функція для пошуку індексу першого нульового елемента
int find_first_zero(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            return i; // Повертаємо індекс
        }
    }
    return -1; // Повертаємо -1, якщо нулів немає
}

// 5. Функція для пошуку індексу останнього нульового елемента
int find_last_zero(int arr[], int n) {
    int i;
    // Йдемо з кінця масиву на початок
    for (i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            return i;
        }
    }
    return -1;
}

// 6. Функція для обчислення добутку елементів між заданими індексами
long long calc_product_between(int arr[], int start_idx, int end_idx) {
    long long prod = 1;
    int i;
    // Починаємо з наступного після першого нуля і закінчуємо перед останнім
    for (i = start_idx + 1; i < end_idx; i++) {
        prod *= arr[i];
    }
    return prod;
}

int main() {
    int repeat;
    
    // Ініціалізація генератора випадкових чисел
    srand(time(0)); 
    
    // Головний зовнішній цикл програми
    do {
        const int MAX_SIZE = 100;
        int a[100];
        int n;
        
        printf("\n--- Array Processing with Functions ---\n");
        
        // Введення розміру масиву з перевіркою
        do {
            printf("Enter the number of array elements (1 to %d): ", MAX_SIZE);
            scanf("%d", &n);
            if (n <= 0 || n > MAX_SIZE) {
                printf("Error: Invalid array size.\n");
            }
        } while (n <= 0 || n > MAX_SIZE);
        
        // Викликаємо функцію ініціалізації
        init_array(a, n);
        
        // Викликаємо функцію виведення
        printf("Generated array:\n");
        print_array(a, n);
        
        // --- Обчислення першого показника ---
        int min_abs_elem = find_min_abs(a, n);
        printf("\n1) The element with the minimum absolute value is: %d\n", min_abs_elem);
        
        // --- Обчислення другого показника ---
        int first_zero = find_first_zero(a, n);
        int last_zero = find_last_zero(a, n);
        
        // Детальна перевірка всіх можливих ситуацій з нулями
        if (first_zero == -1) {
            printf("2) There are no zero elements in the array. Cannot calculate the product.\n");
        } else if (first_zero == last_zero) {
            printf("2) There is only one zero element in the array (at index %d). Cannot calculate the product.\n", first_zero);
        } else if (last_zero - first_zero == 1) {
            printf("2) The first and last zero elements are adjacent (indices %d and %d). There are no elements between them.\n", first_zero, last_zero);
        } else {
            // Якщо все добре - обчислюємо добуток
            long long product = calc_product_between(a, first_zero, last_zero);
            printf("2) The product of elements between the first (idx %d) and last (idx %d) zeros is: %lld\n", first_zero, last_zero, product);
        }

        printf("\nDo you want to run the program again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);
        
    } while (repeat == 1);
    
    printf("Exiting the program...\n");
    return 0;
}