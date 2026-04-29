#include <stdio.h>

int main() {
    int repeat; // Змінна для керування головним циклом

    // Головний зовнішній цикл для багаторазового виконання програми
    do {
        const int MAX_SIZE = 20;
        int A[20][20];
        int n, i, j;
        
        // Змінні для збереження інформації про мінімальний елемент
        int min_val;
        int *min_addr;
        int min_i = 0, min_j = 0;

        printf("\n--- Matrix Minimum Finder (Pointers) ---\n");

        // Введення розміру квадратної матриці із перевіркою ОДЗ
        do {
            printf("Enter the size of the square matrix n (1 to %d): ", MAX_SIZE);
            scanf("%d", &n);
            if (n <= 0 || n > MAX_SIZE) {
                printf("Error: Invalid matrix size.\n");
            }
        } while (n <= 0 || n > MAX_SIZE);

        // Введення елементів матриці з клавіатури
        printf("Enter the elements of the matrix:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("A[%d][%d] = ", i, j);
                // Використовуємо вказівникову арифметику замість &A[i][j]
                // *(A + i) дає адресу початку i-го рядка, додаємо j для зсуву на потрібний стовпець
                scanf("%d", *(A + i) + j); 
            }
        }

        // Ініціалізація початкових значень (беремо перший елемент матриці A[0][0])
        min_val = *(*(A + 0) + 0); 
        min_addr = *(A + 0) + 0; // Зберігаємо адресу першого елемента

        // Пошук мінімального елемента за допомогою вказівників
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Звернення до значення елемента через повну розадресацію: *(*(A + i) + j)
                if (*(*(A + i) + j) < min_val) {
                    min_val = *(*(A + i) + j); // Оновлюємо мінімальне значення
                    min_addr = *(A + i) + j;   // Зберігаємо адресу поточного мінімуму
                    min_i = i;                 // Зберігаємо індекс рядка
                    min_j = j;                 // Зберігаємо індекс стовпця
                }
            }
        }

        // Виведення результату
        // Для адреси використовуємо специфікатор %p та приводимо вказівник до (void*)
        printf("\nmin = %d, address: %p; i = %d, j = %d\n", min_val, (void*)min_addr, min_i, min_j);

        printf("\nDo you want to run the program again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("Exiting the program...\n");

    return 0;
}