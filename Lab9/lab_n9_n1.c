#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ==========================================
// Підпрограма 1 (Завдання А): Видалення кожного другого слова
// Приймає вказівник на оригінальний рядок (input) та рядок-результат (result)
// ==========================================
void remove_even_words(const char *input, char *result) {
    char temp[1000];
    strcpy(temp, input); // Копіюємо, щоб strtok не зламав оригінал
    
    result[0] = '\0'; // Обов'язково очищаємо рядок-результат перед роботою
    
    int word_count = 1;
    char *token = strtok(temp, " \t.,;!?\n");
    
    while (token != NULL) {
        // Якщо слово непарне - залишаємо його
        if (word_count % 2 != 0) {
            strcat(result, token);
            strcat(result, " ");
        }
        word_count++;
        token = strtok(NULL, " \t.,;!?\n");
    }
}

// ==========================================
// Підпрограма 2 (Завдання Б): Видалення слів з однаковими літерами по краях
// ==========================================
void remove_same_letter_words(const char *input, char *result) {
    char temp[1000];
    strcpy(temp, input);
    
    result[0] = '\0'; // Очищаємо рядок-результат
    
    char *token = strtok(temp, " \t.,;!?\n");
    
    while (token != NULL) {
        int len = strlen(token);
        if (len > 0) {
            char first = tolower(token[0]);
            char last = tolower(token[len - 1]);
            
            // Якщо перша і остання літера НЕ збігаються - додаємо слово
            if (!(isalpha(first) && isalpha(last) && first == last)) {
                strcat(result, token);
                strcat(result, " ");
            }
        }
        token = strtok(NULL, " \t.,;!?\n");
    }
}

// ==========================================
// Головна функція
// ==========================================
int main() {
    int repeat;

    do {
        char input_str[1000];
        char result_a[1000];
        char result_b[1000];
        
        printf("\n--- String Processing with Functions (Variant 11) ---\n");
        printf("Enter a text string: ");

        // Зчитуємо текст
        fgets(input_str, sizeof(input_str), stdin);
        
        // Очищення від '\n', який додає fgets
        int len = strlen(input_str);
        if (len > 0 && input_str[len - 1] == '\n') {
            input_str[len - 1] = '\0';
        }

        // Викликаємо наші функції. 
        // Масиви передаються сюди як вказівники на їх перший елемент.
        remove_even_words(input_str, result_a);
        remove_same_letter_words(input_str, result_b);

        // Виведення результатів за допомогою puts(), як вимагає теорія 9-ї лаби
        printf("\nResults:\n");
        puts("a) Text without every second word:");
        puts(result_a);
        
        puts("b) Text without words starting and ending with the same letter:");
        puts(result_b);

        printf("\nDo you want to process another string? (1 - Yes, 0 - Exit): ");
        scanf("%d", &repeat);
        
        // Очищення буфера клавіатури від залишкового Enter
        getchar(); 

    } while (repeat == 1);

    puts("Exiting the program...");
    return 0;
}