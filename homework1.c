#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void task1(){
    float weight;
    printf("Напишите ваш вес: ");
    scanf("%f", &weight);

    if (weight < 60)
        printf("Ваш вес меньше допустимого\n");
    else{ if (weight > 90)
        printf("ваш вес больше допустимого\n");
    else
        printf("Ваш вес подходит\n");}

    return;
}

void task2(){
    float charge;
    printf("Напишите количество топлива: ");
    scanf("%f", &charge);

    if (charge < 500.0)
        printf("Луноход доедет\n");
    else
        printf("Луноход не доедет\n");

    return;
}

void task3(){
    char sim;
    printf("Введите маркировку: ");
    scanf("%c", &sim);

    if (sim >= 'A' && sim <= 'Z')
        printf("Маркировка коректна\n");
    else
        printf("Маркировка не коректна\n");

    return;
}

void task4(){
    time_t time_now;
    time(&time_now);
    struct tm *tm_info = localtime(&time_now);
    int time_now_int = (tm_info->tm_year + 1900) * 10000 + 
    (tm_info->tm_mon + 1)*100 + tm_info->tm_mday;

    int time_user;

    printf("Введите дату в формате ггггммдд: ");
    scanf("%d", &time_user);

    if (time_now_int < time_user)
        printf("Дата находится в будущем\n");
    else{if (time_now_int == time_user)
        printf("Это сегодня\n");
    else
        printf("Дата находится в прошлом\n");}

    return;
}

void task5(){
    double rasch, dey;

    printf("Введите расчетную скорость: ");
    scanf("%lf", &rasch);

    printf("\nВведите действительную скорость: ");
    scanf("%lf", &dey);

    if (abs(rasch - dey) > 1.0)
        printf("Орбита не стабильна\n");
    else
        printf("Орбита стабильна\n");

    return;
}

void task6(){
    int col;
    
    printf("Введите количество участников экспедиции: ");
    scanf("%d", &col);

    if (col > 3 && col < 9)
        printf("Экипаж можно разделить на 2 части");
    else
        printf("Экипаж нельзя разделить");
    
    return;
}

void task7(){
    float x;

    printf("Введите частоту(Ггц): ");
    scanf("%f", &x);

    if (x >= 2.5 && x <= 3.5)
        printf("Связь стабильна");
    else
        printf("Связь не стабильна");
    
    return;
}

void task8(){
    int weight;

    printf("Введите массу груза (в кг): ");
    scanf("%d", &weight);

    if (weight % 4)
        printf("Груз не получится распределить равномерно\n");
    else
        printf("Груз можно распределить по %d кг\n", weight/4);

    return;
}

void task9(){
    double t;

    printf("Введите количество минут: ");
    scanf("%lf", &t);

    int min = (int)t;
    double sec = (t - min) * 60;

    if (min > 4 || min == 0)
        printf("%d минут %.2f секунд\n", min, sec);
    else if (min == 1)
        printf("1 минута %.2f секунд\n", sec);
    else
        printf("%d минуты %.2f секунд\n", min, sec);
    
    return;
}

void task10(){
    int temp;

    printf("Введите температуру корпуса: ");
    scanf("%d", &temp);

    if (temp > -151 && temp < 121)
        printf("Температура в норме");
    else
        printf("Температура не в норме");
    
    return;
}

void task11(){
    float cons;

    printf("Введите концентрацию кослорода: ");
    scanf("%f", &cons);

    if (cons < 15)
        printf("Ниский процент содержания кослорода");
    else
        printf("Все хорошо концентрация кислорода в норме");
    
    return;
}

void task12(){
    int ug;

    printf("Введите угол: ");
    scanf("%d", &ug);

    if (abs(ug) < 181)
        printf("Угол в норме");
    else
        printf("Неверное представление угла");
    
    return;
}

void task13(){
    int kos;

    printf("Введите количество космонавтов");
    scanf("%d", &kos);

    if (kos%2)
        printf("1 косманавт останется");
    else
        printf("Всех космонавтов можно отправить по 2");
    
    return;
}

void task14(){
    int weight;

    printf("Введите массу обьекта: ");
    scanf("%d", &weight);

    printf("Вес на луне составляет %f", (float)weight / 6);

    return;
}

void task15(){
    int hi, weight;

    printf("Введите скорость передачи(Кбит/с): ");
    scanf("%d", &hi);


    printf("\nВведите объем файла(Mb): ");
    scanf("%d", &weight);

    printf("Файл будут передоватся %d секунд\n", (weight*8192 +8191) / hi);

    return;
}

int main() {
    setlocale(LC_ALL, "rus");
    task4();
    return 0;
}
