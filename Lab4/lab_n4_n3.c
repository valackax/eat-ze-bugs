#include <stdio.h>

int main() {
    int repeat;

    do {
        int n, i, j;
        double x;
        double sum = 0.0; // Обнуляємо суму на початку

        printf("\n--- New Calculation ---\n");

        // Запит верхньої межі для зовнішнього циклу (n) з перевіркою на додатність
        do {
            printf("Enter a natural number n (n >= 1): ");
            scanf("%d", &n);
            
            if (n < 1) {
                printf("Error: n must be a natural number (1, 2, 3, ...). Please try again.\n");
            }
        } while (n < 1);

        // Запит дійсного числа x
        printf("Enter a real number x: ");
        scanf("%lf", &x);

        // Зовнішній цикл від i = 1 до n
        for (i = 1; i <= n; i++) {
            
            // Внутрішній цикл від j = i строго до 5 згідно з формулою
            for (j = i; j <= 5; j++) {
                
                // Обчислення виразу та додавання його до загальної суми
                sum += (x + 2.0 * i) / (double)j;
            }
        }

        // Виведення кінцевого результату подвійної суми
        printf("\nCalculated double sum = %.4lf\n", sum);

        printf("\nDo you want to calculate another sum? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);

    } while (repeat == 1); 

    printf("Exiting the program...\n");

    return 0;
}
