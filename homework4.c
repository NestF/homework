#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//###############################################################################

typedef struct {
    char *command;
    void (*func)(char *);
} Command;

void to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void exit_program(char *str) {
    printf("Exiting program.\n");
    exit(0);
}

void task1(){
    Command commands[] = {
        {"upper", to_upper},
        {"lower", to_lower},
        {"reverse", reverse_string},
        {"exit", exit_program}
    };

    char input[100];

    while (true) {
        printf("Введите команду: ");
        scanf("%s", &input);

        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (strcmp(input, commands[i].command) == 0) {
                printf("Введите строку: ");
                char str[100];
                scanf("%s", &str);
                
                commands[i].func(str);
                printf("Результат: %s\n", str);
                break;
            }
        }
    }

    return;
}

//####################################################################################
void remove_spaces(char *str) {
    char *dst = str;
    while (*str) {
        if (*str != ' ') {
            *dst++ = *str;
        }
        str++;
    }
    *dst = '\0';
}

void replace_vowels(char *str) {
    char vowels[] = "aeiouAEIOU";
    while (*str) {
        for (int i = 0; vowels[i]; i++) {
            if (*str == vowels[i]) {
                *str = '*';
                break;
            }
        }
        str++;
    }
}

void invert_case(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

void task2(){
    char *input = NULL;
    size_t len = 0;

    printf("Введите строку: ");
    scanf("%s"&input);

    int choice;
    while (true) {
        scanf("%d", &choice);
    

        switch (choice) {
            case 1:
                remove_spaces(input);
                printf("Результат: %s\n", input);
                break;
            case 2:
                replace_vowels(input);
                printf("Результат: %s\n", input);
                break;
            case 3:
                invert_case(input);
                printf("Результат: %s\n", input);
                break;
            case 4:
                remove_spaces(input);
                replace_vowels(input);
                invert_case(input);
                printf("Результат: %s\n", input);
                break;
            case 5:
                free(input);
                return;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }

    return;
}

//###################################################################################

typedef float (*Operation)(float, float);

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Ошибка: Деление на 0.\n");
        exit();
    }
    return a / b;
}

void task3(){
    char input[100];
    float num1, num2;
    char operator;
    Operation op = NULL;

    printf("Введите выражение (например, 12.5 + 34.2): ");
    scanf("%s", &input);

    
    if (sscanf(input, "%f %c %f", &num1, &operator, &num2) != 3) {
        printf("Ошибка: Некорректный ввод.\n");
        return;
    }

    
    switch (operator) {
        case '+':
            op = add;
            break;
        case '-':
            op = subtract;
            break;
        case '*':
            op = multiply;
            break;
        case '/':
            op = divide;
            break;
        default:
            printf("Ошибка: Неподдерживаемая операция '%c'.\n", operator);
            return;
    }

    float result = op(num1, num2);
    printf("Результат: %.2f\n", result);

    return 0;
}

//###################################################################################
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_length(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

int count_vowels(const char *str) {
    int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int vowel_count(const void *a, const void *b) {
    return count_vowels(*(const char **)a) - count_vowels(*(const char **)b);
}

void task4() {
    int n;
    printf("Введите количество строк: ");
    scanf("%d", &n);

    char **strings = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strings[i] = malloc(100 * sizeof(char));
        printf("Введите строку %d: ", i + 1);
        fgets(strings[i], 100, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0;
    }

    int choice;
    printf("Выберите режим сортировки(1, 2, 3):\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(strings, n, sizeof(char *), compare);
            break;
        case 2:
            qsort(strings, n, sizeof(char *), compare__length);
            break;
        case 3:
            qsort(strings, n, sizeof(char *), vowel_count);
            break;
        default:
            printf("Ошибка: Неверный выбор.\n");
            for (int i = 0; i < n; i++) {
                free(strings[i]);
            }
            free(strings);
            return;
    }

    printf("Отсортированные строки:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);

    return 0;
}

//####################################################################################

char *memory = NULL;
size_t allocated_size = 0;

void alloc_memory(char *size_str) {
    size_t size = atoi(size_str);
    if (size == 0) {
        printf("Ошибка: Неверный размер.\n");
        return;
    }

    if (memory != NULL) {
        printf("Ошибка: Память уже выделена. Сначала освободите её.\n");
        return;
    }

    memory = malloc(size);
    if (memory == NULL) {
        printf("Ошибка: Не удалось выделить память.\n");
        return;
    }

    allocated_size = size;
    printf("Память выделена: %zu байт.\n", allocated_size);
}

void free_memory(char *unused) {
    if (memory == NULL) {
        printf("Ошибка: Память не выделена.\n");
        return;
    }

    free(memory);
    memory = NULL;
    allocated_size = 0;
    printf("Память освобождена.\n");
}

void write_memory(char *text) {
    if (memory == NULL) {
        printf("Ошибка: Память не выделена.\n");
        return;
    }

    if (strlen(text) >= allocated_size) {
        printf("Ошибка: Текст превышает выделенный размер памяти.\n");
        return;
    }

    strcpy(memory, text);
    printf("Текст записан в память.\n");
}

void print_memory(char *unused) {
    if (memory == NULL) {
        printf("Ошибка: Память не выделена.\n");
        return;
    }
    
    printf("Данные в памяти: %s\n", memory);
}

void exit_program(char *unused) {
    if (memory != NULL) 
        free(memory);
        
    printf("Завершение программы.\n");
    exit(0);
}

void task5() {
    Command commands[] = {
        {"alloc", alloc_memory},
        {"free", free_memory},
        {"write", write_memory},
        {"print", print_memory},
        {"exit", exit_program}
    };

    char input[100];
    while (true) {
        printf("Введите команду: ");
        scanf("%s", &input);

        char *command = strtok(input, " ");
        char *argument = strtok(NULL, "");

        int found = 0;
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (strcmp(command, commands[i].command) == 0) {
                commands[i].func(argument);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Ошибка: Неверная команда.\n");
        }
    }

    return;
}