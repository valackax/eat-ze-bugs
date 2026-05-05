#include <stdio.h>
#include <string.h>

// ==========================================
// 1. Функція для дозапису символів у двійковий файл
// ==========================================
void append_to_binary(const char *filename, const char *data) {
    FILE *f;
    
    // Відкриваємо існуючий двійковий файл для додавання даних у його кінець. 
    // Режим "ab" (append binary). Якщо файл не існує, він створюється автоматично.
    f = fopen(filename, "ab");
    
    if (f == NULL) {
        printf("Error: Cannot open the file for appending.\n");
        return;
    }
    
    // Записуємо дані у бінарний файл.
    // Параметри: масив даних, розмір одного елемента, кількість елементів, файловий потік.
    size_t len = strlen(data);
    fwrite(data, sizeof(char), len, f);
    
    // Закриваємо файл, щоб зберегти зміни[cite: 5]
    fclose(f);
    printf("Successfully appended %zu characters to '%s'.\n", len, filename);
}

// ==========================================
// 2. Допоміжна функція для виведення вмісту двійкового файлу
// ==========================================
void print_binary_file(const char *filename) {
    FILE *f;
    char buffer[256];
    size_t bytes_read;
    
    // Відкриваємо двійковий файл для зчитування (режим "rb")[cite: 5]
    f = fopen(filename, "rb");
    
    if (f == NULL) {
        printf("Status: File is currently empty or does not exist.\n");
        return;
    }
    
    printf("Current file content: [");
    
    // Зчитуємо дані блоками за допомогою fread[cite: 5]
    while ((bytes_read = fread(buffer, sizeof(char), 255, f)) > 0) {
        buffer[bytes_read] = '\0'; // Додаємо термінатор, щоб безпечно вивести як рядок
        printf("%s", buffer);
    }
    printf("]\n");
    
    fclose(f);
}

// ==========================================
// Головна функція
// ==========================================
int main() {
    int repeat;
    char filename[] = "data.bin"; // Стандартне розширення для бінарних файлів

    do {
        char input_chars[200];
        
        printf("\n--- Binary File Appender ---\n");
        
        // Спочатку показуємо, що зараз знаходиться у файлі
        print_binary_file(filename);
        
        // Просимо користувача ввести набір символів для дозапису
        printf("\nEnter a set of characters to append: ");
        fgets(input_chars, sizeof(input_chars), stdin);
        
        // Видаляємо '\n', якщо він був зчитаний функцією fgets
        int len = strlen(input_chars);
        if (len > 0 && input_chars[len - 1] == '\n') {
            input_chars[len - 1] = '\0';
        }
        
        // Викликаємо нашу головну функцію для дозапису
        append_to_binary(filename, input_chars);
        
        // Знову показуємо вміст файлу, щоб довести, що символи додалися
        printf("\nAfter append:\n");
        print_binary_file(filename);

        // Запит на повторення програми
        printf("\nDo you want to append more? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);
        
        // Очищення буфера клавіатури
        while(getchar() != '\n'); 

    } while (repeat == 1);

    printf("Exiting the program...\n");
    return 0;
}