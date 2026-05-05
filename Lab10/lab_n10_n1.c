#include <stdio.h>
#include <stdlib.h>

int main() {
    int repeat; // Змінна для керування головним циклом

    // Головний зовнішній цикл для багаторазового виконання програми
    do {
        FILE *f; // Оголошуємо файлову змінну-вказівник[cite: 5]
        char filename[] = "numbers.txt"; // Ім'я нашого текстового файлу
        
        int n, i;
        float p, temp_val;
        int greater_count = 0; // Лічильник чисел, більших за p

        printf("\n--- File Processing ---\n");

        // 1. Введення кількості елементів файлу із перевіркою ОДЗ
        do {
            printf("Enter the number of elements to store in the file (n): ");
            scanf("%d", &n);
            if (n <= 0) {
                printf("Error: The number of elements must be greater than 0.\n");
            }
        } while (n <= 0);

        // 2. Введення числа p (порогового значення)
        printf("Enter the threshold value (p): ");
        scanf("%f", &p);

        // ==========================================
        // БЛОК ЗАПИСУ У ФАЙЛ
        // ==========================================
        
        // Відкриваємо файл у режимі "w" - запис (створить новий або перезапише існуючий)[cite: 5]
        f = fopen(filename, "w");
        
        // Перевірка, чи успішно відкрито файл[cite: 5]
        if (f == NULL) {
            printf("Error: Cannot create or open the file for writing.\n");
            return 1; // Завершуємо програму з помилкою
        }

        printf("Enter %d real numbers:\n", n);
        for (i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            scanf("%f", &temp_val);
            
            // Записуємо введене число у файл. Додаємо \n, щоб кожне число було з нового рядка[cite: 5]
            fprintf(f, "%f\n", temp_val); 
        }
        
        // Обов'язково закриваємо файл після запису, щоб зберегти дані на диску[cite: 5]
        fclose(f); 
        printf("Data successfully written to '%s'.\n", filename);

        // ==========================================
        // БЛОК ЗЧИТУВАННЯ ТА ОБРОБКИ
        // ==========================================
        
        // Відкриваємо той самий файл у режимі "r" - зчитування існуючого файлу[cite: 5]
        f = fopen(filename, "r");
        
        if (f == NULL) {
            printf("Error: Cannot open the file for reading.\n");
            return 1;
        }

        // Зчитуємо дані з файлу за допомогою fscanf. 
        // Цикл працює, поки fscanf успішно зчитує елементи (повертає значення > 0)[cite: 5]
        while (fscanf(f, "%f", &temp_val) > 0) {
            // Перевіряємо умову завдання: чи елемент більший за p
            if (temp_val > p) {
                greater_count++;
            }
        }
        
        // Закриваємо файл після завершення роботи з ним[cite: 5]
        fclose(f);

        // Виведення результату
        printf("\nResult:\n");
        printf("There are %d elements in the file strictly greater than %.2f.\n", greater_count, p);

        // Запит на повторення програми
        printf("\nDo you want to run the program again? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);
        
        // Очищення буфера клавіатури від залишкового символу Enter
        while(getchar() != '\n'); 

    // Цикл повторюється, якщо користувач ввів 1
    } while (repeat == 1);

    printf("Exiting the program...\n");
    return 0;
}