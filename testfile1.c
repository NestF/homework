#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = " ,!";
    
    size_t length = strcspn(str1, str2);
    printf("Длина начального сегмента: %zu\n", length); // Вывод: 5
    return 0;
}