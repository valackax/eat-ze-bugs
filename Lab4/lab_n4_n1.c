#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    int denom; // Змінна для зберігання знаменника
    double f;  // Змінна для кінцевого результату
    int repeat;

    do {
        printf("\n--- New Calculation ---\n");

        // Внутрішній цикл для введення даних та перевірки області допустимих значень
        do {
            printf("Enter integer x: ");
            scanf("%d", &x); // Зчитуємо x
            
            printf("Enter integer y: ");
            scanf("%d", &y); // Зчитуємо y

            // Обчислюємо знаменник
            denom = 1 + x * x + y * y;

            // Перевіряємо чи не виникає ділення на нуль
            if (denom == 0) {
                printf("Error: division by 0 occurs for the given x and y values. Please enter other values.\n");
            }
            
        // Повторюємо запит даних якщо знаменник дорівнює нулю
        } while (denom == 0); 

        // Обчислюємо значення функції з перетворенням типу для точності
        f = (double)(x * x + x * y - y * y) / denom;

        // Виводимо результат
        printf("Function value f = %.2lf\n", f);

        // Запитуємо користувача чи хоче він виконати ще одне обчислення
        printf("\nDo you want to calculate another pair? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    // Головний цикл повториться якщо користувач введе 1
    } while (repeat == 1); 

    printf("Exiting the program...\n");

    return 0;
}
