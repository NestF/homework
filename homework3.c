#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void task1(){
    char ships[100][51];
    int n;

    printf("Введите количество кораблей (максимум %d): ", 100);
    scanf("%d", &n);

    printf("Введите названия кораблей:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", ships[i]);
    }

    for (int i = 0; i < n; i++) {
        if (strncmp(ships[i], "SS", 2) == 0) {
            printf("Первый корабль: %s\n", ships[i]);
            return;
        }
    }

    printf("Не найдено\n");
    return;
}

void task2(){
    char message[100];
    printf("Введите сообщение: ");
    scanf("%s", &message);

    int start = strcspn(message, "#*");
    
    if (start < strlen(message)) {
        while (message[start] == '#' || message[start] == '*')
            start++;

        int end = strlen(message) - 1;
        while (end >= start && (message[end] == '#' || message[end] == '*'))
            end--;

        if (start <= end) {
            int length = end - start + 1;
            message[end + 1] = '\0';
            printf("Очищенное сообщение: %s\n", message + start);
            printf("Длина сообщения: %d\n", length);
        } else
            printf("Сообщение не найдено\n");
    } else
        printf("Сообщение не найдено\n");

    return;
}

void task3() {
    char astronauts[50];
    printf("Введите список космонавтов через ';': ");
    scanf("%s", astronauts);

    char *r = strtok(astronauts, ";");
    
    while (r != NULL) {
        printf("%s\n", r);
        r = strtok(NULL, ";");
    }

    return;
}

void task4(){
    char code[50];

    printf("Введите код запуска: ");
    scanf("%s", &code);

    if (!strcasecmp(code, "LAUNCH-2025"))
        printf("Код принят\n");
    else
        printf("Ошибка: неверный код!\n");

    return;
}

void task5(){
    char report[201];
    
    printf("Введите отчет: ");
    scanf("%s", &report);

    char *copy = strdup(report);

    printf("\nОригинал: %s\n", report);
    printf("Копия: %s\n", copy);

    free(copy);

    return;
}

int main(){
    task5();
    return 0;
}